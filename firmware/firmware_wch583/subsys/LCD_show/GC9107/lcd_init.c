#include "lcd_init.h"
#include "SPI/mySPI.h"
void LCD_GPIO_Init(void) {

    //cs
    GPIOA_ModeCfg(PIN_LCD_CS, GPIO_ModeOut_PP_5mA);
    LCD_CS_Set();

    GPIOB_ModeCfg(PIN_LCD_DC, GPIO_ModeOut_PP_5mA);

    GPIOB_ModeCfg(PIN_LCD_BL, GPIO_ModeOut_PP_5mA);

    GPIOB_ModeCfg(PIN_LCD_RST, GPIO_ModeOut_PP_5mA);

    /* SPI 0 */
//    GPIOA_ModeCfg( GPIO_Pin_13 | GPIO_Pin_14, GPIO_ModeOut_PP_5mA);
//    SPI0_MasterDefInit();
//    SPI0_CLKCfg(2);




}

/******************************************************************************
 ����˵����LCD��������д�뺯��
 ������ݣ�dat  Ҫд��Ĵ�������
 ����ֵ��  ��
 ******************************************************************************/
__HIGH_CODE
void LCD_Writ_Bus(u8 dat) {

    LCD_CS_Clr();

    MySPIsenddata(dat);
    LCD_CS_Set();
}

__HIGH_CODE
void LCD_WR_buf(uint8_t *dat, uint16_t len)
{
//  LCD_Writ_Bus(dat);
    LCD_CS_Clr();
    MySPIsendbuf(dat, len);
    LCD_CS_Set();
}

/******************************************************************************
 ����˵����LCDд������
 ������ݣ�dat д�������
 ����ֵ��  ��
 ******************************************************************************/
__HIGH_CODE
void LCD_WR_DATA8(u8 dat) {
//    LCD_Writ_Bus(dat);
    LCD_CS_Clr();
    MySPIsenddata(dat);
    LCD_CS_Set();
}

/******************************************************************************
 ����˵����LCDд������
 ������ݣ�dat д�������
 ����ֵ��  ��
 ******************************************************************************/
__HIGH_CODE
void LCD_WR_DATA(u16 dat) {

    LCD_Writ_Bus(dat >> 8);
       LCD_Writ_Bus(dat);

}

/******************************************************************************
 ����˵����LCDд������
 ������ݣ�dat д�������
 ����ֵ��  ��
 ******************************************************************************/
__HIGH_CODE
void LCD_WR_REG(u8 dat) {
    LCD_DC_Clr(); //д����
    LCD_Writ_Bus(dat);
    LCD_DC_Set(); //д����
}

/******************************************************************************
 ����˵����������ʼ�ͽ�����ַ
 ������ݣ�x1,x2 �����е���ʼ�ͽ�����ַ
 y1,y2 �����е���ʼ�ͽ�����ַ
 ����ֵ��  ��
 ******************************************************************************/
__HIGH_CODE
void LCD_Address_Set(u16 x1, u16 y1, u16 x2, u16 y2) {
    if (USE_HORIZONTAL == 0) {
        LCD_WR_REG(0x2a); //�е�ַ����
        LCD_WR_DATA(x1 + 2);
        LCD_WR_DATA(x2 + 2);
        LCD_WR_REG(0x2b); //�е�ַ����
        LCD_WR_DATA(y1 + 1);
        LCD_WR_DATA(y2 + 1);
        LCD_WR_REG(0x2c); //������д
    } else if (USE_HORIZONTAL == 1) {
        LCD_WR_REG(0x2a); //�е�ַ����
        LCD_WR_DATA(x1 + 2);
        LCD_WR_DATA(x2 + 2);
        LCD_WR_REG(0x2b); //�е�ַ����
        LCD_WR_DATA(y1 + 1);
        LCD_WR_DATA(y2 + 1);
        LCD_WR_REG(0x2c); //������д
    } else if (USE_HORIZONTAL == 2) {
        LCD_WR_REG(0x2a); //�е�ַ����
        LCD_WR_DATA(x1 + 1);
        LCD_WR_DATA(x2 + 1);
        LCD_WR_REG(0x2b); //�е�ַ����
        LCD_WR_DATA(y1 + 2);
        LCD_WR_DATA(y2 + 2);
        LCD_WR_REG(0x2c); //������д
    } else {
        LCD_WR_REG(0x2a); //�е�ַ����
        LCD_WR_DATA(x1 + 1);
        LCD_WR_DATA(x2 + 1);
        LCD_WR_REG(0x2b); //�е�ַ����
        LCD_WR_DATA(y1 + 2);
        LCD_WR_DATA(y2 + 2);
        LCD_WR_REG(0x2c); //������д
    }
}

void LCD_Init(void) {
    LCD_GPIO_Init(); //��ʼ��GPIO

    LCD_RES_Clr(); //��λ
    DelayMs(100);
    LCD_RES_Set();
    DelayMs(100);



//	LCD_WR_REG(0xEF);			
//	LCD_WR_REG(0xFE);

    LCD_WR_REG(0xB0);
    LCD_WR_DATA8(0xC0);
    LCD_WR_REG(0xB2);
    LCD_WR_DATA8(0x2F);
    LCD_WR_REG(0xB3);
    LCD_WR_DATA8(0x03);
    LCD_WR_REG(0xB6);
    LCD_WR_DATA8(0x19);
    LCD_WR_REG(0xB7);
    LCD_WR_DATA8(0x01);

    LCD_WR_REG(0xAC);
    LCD_WR_DATA8(0xCB);
    LCD_WR_REG(0xAB);
    LCD_WR_DATA8(0x0e);

    LCD_WR_REG(0xB4);
    LCD_WR_DATA8(0x04);

    LCD_WR_REG(0xA8);
    LCD_WR_DATA8(0x19);

    LCD_WR_REG(0x3A);
    LCD_WR_DATA8(0x05);

    LCD_WR_REG(0x36);
    if (USE_HORIZONTAL == 0)
        LCD_WR_DATA8(0xC8);
    else if (USE_HORIZONTAL == 1)
        LCD_WR_DATA8(0x08);
    else if (USE_HORIZONTAL == 2)
        LCD_WR_DATA8(0x68);
    else
        LCD_WR_DATA8(0xA8);

    LCD_WR_REG(0xb8);
    LCD_WR_DATA8(0x08);

    LCD_WR_REG(0xE8);
    LCD_WR_DATA8(0x24);

    LCD_WR_REG(0xE9);
    LCD_WR_DATA8(0x48);

    LCD_WR_REG(0xea);
    LCD_WR_DATA8(0x22);

    LCD_WR_REG(0xC6);
    LCD_WR_DATA8(0x30);
    LCD_WR_REG(0xC7);
    LCD_WR_DATA8(0x18);

    LCD_WR_REG(0xF0);
    LCD_WR_DATA8(0x1F);
    LCD_WR_DATA8(0x28);
    LCD_WR_DATA8(0x04);
    LCD_WR_DATA8(0x3E);
    LCD_WR_DATA8(0x2A);
    LCD_WR_DATA8(0x2E);
    LCD_WR_DATA8(0x20);
    LCD_WR_DATA8(0x00);
    LCD_WR_DATA8(0x0C);
    LCD_WR_DATA8(0x06);
    LCD_WR_DATA8(0x00);
    LCD_WR_DATA8(0x1C);
    LCD_WR_DATA8(0x1F);
    LCD_WR_DATA8(0x0f);

    LCD_WR_REG(0xF1);
    LCD_WR_DATA8(0X00);
    LCD_WR_DATA8(0X2D);
    LCD_WR_DATA8(0X2F);
    LCD_WR_DATA8(0X3C);
    LCD_WR_DATA8(0X6F);
    LCD_WR_DATA8(0X1C);
    LCD_WR_DATA8(0X0B);
    LCD_WR_DATA8(0X00);
    LCD_WR_DATA8(0X00);
    LCD_WR_DATA8(0X00);
    LCD_WR_DATA8(0X07);
    LCD_WR_DATA8(0X0D);
    LCD_WR_DATA8(0X11);
    LCD_WR_DATA8(0X0f);

    LCD_WR_REG(0x21);
    DelayMs(120);
    LCD_WR_REG(0x11);
    DelayMs(120);
    LCD_WR_REG(0x29);
    DelayMs(120);

//    LCD_Fill(0, 0, LCD_W, LCD_H, 0x0000);

//    LCD_BLK_Set(); //�򿪱���
//    DelayMs(100);
}

