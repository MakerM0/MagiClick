#include "temperature.h"


static uint8_t cnt = 0;
static void init(void *data)
{
	cnt = 0;
}

static void enter(void *data)
{
	uint16_t temp_forecolor = C_GRAY;
	uint16_t temp_bgcolor = C_BLACK;

	uint16_t humi_forecolor = C_GRAY;
	uint16_t humi_bgcolor = C_LIGHT_GRAY;
	// insert code
	UG_FillScreen(C_BLACK);
	UG_FillFrame(0, 0, 127, 63, temp_bgcolor);
	UG_FillFrame(0, 64, 127, 127, humi_bgcolor);

	UG_FontSelect(FONT_8X12);
	UG_PutChar('C', 99, 4, temp_forecolor, temp_bgcolor);

	UG_FontSelect(FONT_8X12);
	UG_PutChar('%', 99, 70, temp_bgcolor, humi_bgcolor);
//	manager_startEventOnce(5);

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


	default:
		break;
	}
}

static void event(void *data)
{


}

static void quit(void *data)
{
//	manager_stopEvent();
	//
	manager_setBusy(true);
}

#include "img.h"
page_t page_temperature =
{ .init = init, .enter = enter, .exit = quit, .loop = loop, .event=event,.title_en = "Temper&Humi",
		.title_cn = "ÎÂÊª¶È", .icon = img_bits, .icon_width =
		img_width, .icon_height = img_height, .sleep_enable = false,
		.wakeup_btn_effect_enable = false, .acc_enable = false,

};
