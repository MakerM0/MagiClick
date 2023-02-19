#include "media.h"
#include "hidconsumer.h"
#include "img_music_play.h"
#include "img_music_circle.h"
#include "img_music_next.h"
#include "img_music_prev.h"

static uint8_t cnt = 0;
static void init(void *data)
{
	cnt = 0;
}

static void enter(void *data)
{
	// insert code
	UG_FillScreen(C_BLACK);
	manager_startEventOnce(5);

	//
	manager_setBusy(false);
}

static void loop(void *data)
{
	KEY_TYPE key;
	key = HAL_KeyGet();
	switch (key)
	{

	case KEY1_LONG:

		manager_switchToParent();
		break;

	case KEY1_SHORT:

		hidEmuSendConsumerReport(MUSIC_PLAYPAUSE, 0x00);
		hidEmuSendConsumerReport(0, 0);
		break;

	case KEY2_SHORT:

		hidEmuSendConsumerReport(MUSIC_PREV, 0x00);
		hidEmuSendConsumerReport(0, 0);
		break;
	case KEY3_SHORT:

		hidEmuSendConsumerReport(MUSIC_NEXT, 0x00);
		hidEmuSendConsumerReport(0, 0);
		break;

	default:
		break;
	}
}

static void event(void *data)
{

	switch (cnt)
	{
	case 0:
		LCD_DrawMonoXBMFast(32, 32, 64, 64, img_music_circle_bits, C_LIGHT_BLUE ,
			C_BLACK);
		break;
	case 1:
		LCD_DrawMonoXBMFast(48, 48, 32, 32, img_music_play_bits, C_LIGHT_BLUE,
				C_GREEN);
		break;
	case 2:
		LCD_DrawMonoXBMFast(0, 48, 32, 32, img_music_prev_bits, C_LIGHT_BLUE,
			C_BLACK);
		break;
	case 3:
		LCD_DrawMonoXBMFast(96, 48, 32, 32, img_music_next_bits, C_LIGHT_BLUE,
			C_BLACK);
		break;
	default: break;

	}




	if(cnt<4){
		manager_startEventOnce(80);
	}
	cnt++;

}

static void quit(void *data)
{
	manager_stopEvent();
	//
	manager_setBusy(true);
}

#include "img.h"
page_t page_media =
{ .init = init, .enter = enter, .exit = quit, .loop = loop, .event=event,.title_en = "media",
		.title_cn = "多媒体", .icon = img_bits, .icon_width =
		img_width, .icon_height = img_height, .sleep_enable = false,
		.wakeup_btn_effect_enable = false, .acc_enable = false,

};
