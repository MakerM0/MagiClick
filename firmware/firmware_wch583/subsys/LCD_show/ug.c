/*
 * ug.c
 *
 *  Created on: Dec 3, 2022
 *      Author: qwert
 */

#include "ug.h"

UG_GUI gui;

static UG_RESULT HW_FillFrame(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2,
        UG_COLOR c) {
    if (x1 < 0)
        x1 = 0;
    if (y1 < 0)
        y1 = 0;
    if (x2 > LCD_W)
        x2 = LCD_W;
    if (y2 > LCD_H)
        y2 = LCD_H;
    LCD_Fill(x1, y1, x2 + 1, y2 + 1, c);

    return UG_RESULT_OK;
}

static UG_RESULT HW_DrawLine(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2,
        UG_COLOR c) {

    LCD_DrawLine(x1, y1, x2, y2, c);
    return UG_RESULT_OK;
}

static void pset(UG_S16 x, UG_S16 y, UG_COLOR c) {
    if (x >= 0 && x < LCD_W && y >= 0 && y < LCD_H)
        LCD_DrawPoint(x, y, c);
}

UG_DEVICE ug_device={
        LCD_W,
        LCD_H,
        pset,
        NULL
};

uint16_t UG_GetStringWidth(char *str)
{

     uint16_t width=0;
     UG_GUI *gui;
     gui = UG_GetGUI();

      if( gui->currentFont.is_old_font)
      {
          width = (uint16_t )tmos_strlen(str)*gui->font[1];
      }
      else
     {
          while (*str != 0)
         {
             width += gui->font[10+(*str)-0x20];//因为自定义字体文件的字符是从0x20开始的，因此需要减去
             str++;
//             LCD_ShowIntNum0(0, 15, width, 3, C_RED, C_YELLOW, 12, 0);
         }
     }
     return width;
}

//https://github.com/Bodmer/TFT_eSPI
/***************************************************************************************
** Function name:           alphaBlend
** Description:             Blend 16bit foreground and background
*************************************************************************************x*/
uint16_t UG_alphaBlend(uint8_t alpha, uint16_t fgc, uint16_t bgc)
{
  // Split out and blend 5 bit red and blue channels
  uint32_t rxb = bgc & 0xF81F;
  rxb += ((fgc & 0xF81F) - rxb) * (alpha >> 2) >> 6;
  // Split out and blend 6 bit green channel
  uint32_t xgx = bgc & 0x07E0;
  xgx += ((fgc & 0x07E0) - xgx) * alpha >> 8;
  // Recombine channels
  return (rxb & 0xF81F) | (xgx & 0x07E0);
}
/***************************************************************************************
** Function name:           fillRectVGradient
** Description:             draw a filled rectangle with a vertical colour gradient
***************************************************************************************/
void UG_fillRectVGradient(int16_t x, int16_t y, int16_t w, int16_t h, uint32_t color1, uint32_t color2)
{
  if ((w < 1) || (h < 1)) return;


  float delta = -255.0/h;
  float alpha = 255.0;
  uint32_t color = color1;

  while (h--) {

//    drawFastHLine(x, y++, w, color);
    UG_DrawLine(x, y, x+w, y, color);
    y++;
    alpha += delta;
    color = UG_alphaBlend((uint8_t)alpha, color1, color2);
  }

}


/***************************************************************************************
** Function name:           fillRectHGradient
** Description:             draw a filled rectangle with a horizontal colour gradient
***************************************************************************************/
void UG_fillRectHGradient(int16_t x, int16_t y, int16_t w, int16_t h, uint32_t color1, uint32_t color2)
{
  if ((w < 1) || (h < 1)) return;


  float delta = -255.0/w;
  float alpha = 255.0;
  uint32_t color = color1;

  while (w--) {

    UG_DrawLine(x, y, x, y+h, color);
    x++;
    alpha += delta;
    color = UG_alphaBlend((uint8_t)alpha, color1, color2);
  }

}

/***************************************************************************************
** Function name:           color565
** Description:             convert three 8 bit RGB levels to a 16 bit colour value
***************************************************************************************/
uint16_t UG_color565(uint8_t r, uint8_t g, uint8_t b)
{
  return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}





void ug_init() {
    LCD_Init(); //LCD初始化
    UG_Init(&gui, &ug_device);
     UG_DriverRegister( DRIVER_DRAW_LINE, HW_DrawLine ) ;
    UG_DriverRegister(DRIVER_FILL_FRAME, HW_FillFrame);
//     UG_DriverEnable ( DRIVER_DRAW_LINE ) ;
    UG_DriverEnable(DRIVER_FILL_FRAME);
    UG_FillScreen(C_BLACK);

//    UG_FontSelect(&FONT_6X10);
//
//    UG_FillCircle(64, 64, 40, C_BLUE);
//    UG_SetForecolor(C_WHITE);
//    UG_PutString(0, 0, "Hello");
//
//    UG_DrawFrame(0, 0, 127, 127, C_WHITE);
}
