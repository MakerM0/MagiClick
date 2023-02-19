#include "lucky.h"

static uint32_t cnt = 0;

static bool f_start = false;
static void init(void *data)
{
	f_start = false;
}

static void enter(void *data)
{

	UG_FillScreen(C_BLACK);

	UG_SetBackcolor(C_BLACK);
	UG_FontSelect(FONT_32X53);
	UG_SetForecolor(C_GREEN_YELLOW);

	uint16_t width = UG_GetStringWidth("0");

	UG_PutString((LCD_W - width) / 2, 37, "0");

	UG_FontSetTransparency(0);

	manager_setBusy(false);
}

static void event(void *data)
{
	static uint8_t num_old = 0;
	uint8_t num = 0;
	char buffer[12];
	if (f_start)
	{
		do
		{
			num = tmos_rand()%10;
		} while (num == num_old);
		num_old = num;

		tmos_memset(buffer, 0, 2);
		snprintf(buffer, 2, "%d", num % 10);
		uint16_t width = UG_GetStringWidth(buffer);

		UG_PutString((LCD_W - width) / 2, 37, buffer);

		manager_startEventOnce(80);

	}

}

static void loop(void *data)
{
	KEY_TYPE key = HAL_KeyGet();
	switch (key)
	{
	case KEY1_DOWN:
		f_start = !f_start;

		manager_stopEvent();
		manager_startEventOnce(2);
		break;      //计数开始
	case KEY1_LONG: //长按
		manager_switchToParent(); //进入父项目 //退出
		break;

	default:
		break;
	}
}

static void quit(void *data)
{
	UG_FontSetTransparency(1);
	manager_setBusy(true);

}

#include "img.h"
page_t page_lucky =
{ .init = init, .enter = enter, .exit = quit, .loop = loop, .event = event,
		.title_en = "Lucky", .title_cn = "幸运数", .icon = img_bits, .icon_width =
		img_width, .icon_height = img_height,

};
