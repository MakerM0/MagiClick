#include "counter.h"
#include "img_muyu.h"
static uint32_t cnt = 0;

#define BUF_LENGTH 10
static char buffer[BUF_LENGTH];
unsigned char *gImage_img_muyu[]={gImage_img_muyu1,gImage_img_muyu2,gImage_img_muyu3,gImage_img_muyu1};
static void init(void *data)
{

	tmos_memset(buffer, 0, BUF_LENGTH);
}

static void enter(void *data)
{

	UG_FillScreen(C_WHITE);
	UG_SetBackcolor(C_WHITE);



	UG_FontSelect(FONT_arial_25X28);
	UG_SetForecolor(C_DARK_GREEN);
	snprintf(buffer, BUF_LENGTH, "%d", cnt);
	uint16_t width = UG_GetStringWidth(buffer);

	UG_PutString((LCD_W-width)/2, 95, buffer);

	LCD_ShowPicture(16, 0, 96, 96, gImage_img_muyu[0]);

	manager_setBusy(false);
}
static uint8_t cnt_img=0;
static void event(void *data)
{

	if(cnt_img==0)
	{
		tmos_memset(buffer, 0, BUF_LENGTH);
		snprintf(buffer, BUF_LENGTH, "%d", cnt);
		uint16_t width = UG_GetStringWidth(buffer);
		UG_FillFrame((LCD_W-width)/2, 95,   (LCD_W+width)/2, 125, C_WHITE);
		UG_PutString((LCD_W-width)/2, 95, buffer);
	}


	LCD_ShowPicture(16, 0, 96, 96, gImage_img_muyu[cnt_img]);

	cnt_img++;

	if(cnt_img<4)
	{

		manager_startEventOnce(150);
	}

}

static void loop(void *data)
{
	KEY_TYPE key = HAL_KeyGet();
	switch (key)
	{
	case KEY1_DOWN:
		cnt++;
		cnt_img=0;
		manager_stopEvent();
		manager_startEventOnce(2);
		break;      //计数开始
	case KEY3_LONG: //长按
		manager_switchToParent(); //进入父项目 //退出
		break;
	case KEY2_LONG: //长按
		manager_switchToParent(); //进入父项目 //退出
		break;
	default:
		break;
	}
}

static void quit(void *data)
{

	manager_setBusy(true);

}

#include "img.h"
page_t page_counter =
{ .init = init, .enter = enter, .exit = quit, .loop = loop, .event = event,
		.title_en = "Counter", .title_cn = "计数器", .icon = img_bits,
		.icon_width = img_width, .icon_height = img_height,

};
