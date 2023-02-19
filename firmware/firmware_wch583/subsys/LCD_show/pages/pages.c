#include "pages.h"
#include "LCD_show/manager/manager.h"

#include "LCD_show/pages/clock/clock.h"
#include "LCD_show/pages/media/media.h"
#include "LCD_show/pages/stopwatch/stopwatch.h"
#include "LCD_show/pages/shutter/shutter.h"
#include "LCD_show/pages/counter/counter.h"
#include "LCD_show/pages/lucky/lucky.h"
#include "LCD_show/pages/temperature/temperature.h"

//需要添加自己的功能页面
page_t *pages[] =
{ &page_main, &page_clock, &page_media, &page_stopwatch, &page_shutter,
		&page_counter, &page_lucky,&page_temperature

};

static const uint8_t pages_num = ARRAY_SIZE(pages);

static int16_t page_index = 1;
static int16_t page_index_old = 0;


static void dispBar()
{
//	UG_FillFrame(0, 0, 127, 12, C_DARK_OLIVE_GREEN);

	char buffer[50];
	strftime(buffer, 100, "%F %T", mytime);

	uint16_t year = mytime->tm_year + 1900;
	uint16_t yday = mytime->tm_yday;
	uint8_t month = mytime->tm_mon + 1;
	uint8_t week = mytime->tm_wday + 1;
	uint8_t day = mytime->tm_mday;
	uint8_t hour = mytime->tm_hour;
	uint8_t minute = mytime->tm_min;
	uint8_t second = mytime->tm_sec;

	UG_FontSetTransparency(0);

	UG_FontSelect(FONT_8X12);

	UG_SetBackcolor(C_DARK_OLIVE_GREEN);
	UG_SetForecolor(C_BLACK);


	snprintf(buffer,16,"%02d-%02d",month,  day);
	UG_PutString(5, 1, buffer);

	snprintf(buffer,16,"%02d:%02d",hour,  minute);
	UG_PutString(80, 1, buffer);

//	snprintf(buffer,16,"%02d:02%d",month,  day);
//	UG_PutString(44, 0, buffer);




	UG_FontSetTransparency(1);

}



static void init(void *data)
{

	manager.index = 0;

}

static void enter(void *data)
{
	char buffer[10];
	uint16_t width = pages[page_index]->icon_width;
	uint16_t height = pages[page_index]->icon_height;

	PRINT("enter:%d  ", page_index);

	UG_FillFrame(0, 0, 127, 12, C_DARK_OLIVE_GREEN);
	UG_FillFrame(0, 13, 127, 127, C_BLACK);
//	UG_FillScreen(C_BLACK);

	if (pages[page_index]->icon)
	{
		UG_SetBackcolor(C_BLACK);
		UG_SetForecolor(C_DIM_GRAY);
		UG_FontSelect(FONT_6X10);
		UG_FontSetTransparency(0);
		sprintf(buffer, "%d/%d  ", page_index, pages_num - 1);

		UG_PutString(55, 118, buffer);
		UG_FontSetTransparency(1);


		UG_FontSelect(FONT_impact_14X18);
		UG_SetForecolor(C_DARK_GRAY);
		uint16_t title_width = UG_GetStringWidth(pages[page_index]->title_en);
		UG_PutString((LCD_W - title_width) / 2, 92,
				pages[page_index]->title_en);

		LCD_DrawMonoImgFast((LCD_W - width) / 2, 25, width, height,
				pages[page_index]->icon, C_GREEN, C_BLACK);
	}


	manager_startEventOnce(5);

	manager_setBusy(false);
}

void switchpages()
{
	char buffer[10];

	uint16_t width;
	uint16_t height;

	width = pages[page_index]->icon_width;
	height = pages[page_index]->icon_height;

//    UG_FillFrame(0, 95, 127, 95+UG_GetFontHeight(FONT_impact_14X18)+3, tmos_rand()>>20);
	UG_FillFrame(0, 92, 127, 112, C_BLACK);
	UG_SetBackcolor(C_BLACK);
	UG_FontSelect(FONT_6X10);
	UG_SetForecolor(C_DIM_GRAY);
	UG_FontSetTransparency(0);
	sprintf(buffer, "%d/%d   ", page_index, pages_num - 1);
	UG_PutString(55, 118, buffer);
			UG_FontSetTransparency(1);

	UG_SetForecolor(C_DARK_GRAY);
	UG_SetBackcolor(C_BLACK);
	UG_FontSelect(FONT_impact_14X18);
	uint16_t title_width_old = UG_GetStringWidth(
			pages[page_index_old]->title_en);
	uint16_t title_width = UG_GetStringWidth(pages[page_index]->title_en);
	UG_PutString((LCD_W - title_width) / 2, 92, pages[page_index]->title_en);

	LCD_DrawMonoImgFast((LCD_W - width) / 2, 25, width, height,
			pages[page_index]->icon, tmos_rand() >> 16, C_BLACK);

}

static void switchNext()
{
	page_index_old = page_index;
	page_index++;
	if (page_index == pages_num)
		page_index = 1;
}

static void switchPrev()
{
	page_index_old = page_index;
	page_index--;
	if (page_index == 0)
		page_index = pages_num - 1;
}
#include "hidconsumer.h"
void poweroff(void )
{
	GPIOA_ResetBits(GPIO_Pin_4);
	GPIOA_ModeCfg(GPIO_Pin_4,GPIO_ModeOut_PP_5mA);
	DelayMs(100);
}
static void loop(void *data)
{

	KEY_TYPE key = HAL_KeyGet();
//    if(key!=KEY_NONE)PRINT("%d\r\n ",key);

//    if(key!=KEY_NONE)tmos_set_event(BEEP_TaskID, BEEP_SHOCK_EVT);
	switch (key)
	{

	case KEY1_LONG:
		manager.index = page_index;
		manager_switchToChild(); //进入子项目
		break;

	case KEY2_DOWN:                //上一功能
		switchPrev();
		//发送切换事件
		tmos_set_event(show_TaskID, SHOW_SWITCH_PAGES_EVENT);

		break;

	case KEY3_DOWN:                  //下一功能
		switchNext();
		//发送切换事件
		tmos_set_event(show_TaskID, SHOW_SWITCH_PAGES_EVENT);

		break;
	case KEY1_DOUBLE:
		case KEY1_TRIPLE:
		case KEY2_DOUBLE:
			case KEY2_TRIPLE:
	case KEY3_DOUBLE:
	case KEY3_TRIPLE: poweroff();
		break;
	default:
		break;
	}

}
static void event(void *data)
{
	dispBar();
	manager_startEventOnce(10000);
}

static void quit(void *data)
{

	manager_setBusy(true);

	// free(buffer);
}

page_t page_main =
{ .init = init, .enter = enter, .exit = quit, .loop = loop, .event = event,
		.title_en = "main", .title_cn = "主页", .icon = NULL, .icon_width = 0,
		.icon_height = 0, .sleep_enable = true, .wakeup_btn_effect_enable =
				false, .acc_enable = true,

};
