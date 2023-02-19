#include "stopwatch.h"

static uint32_t record[8];
static uint8_t id;
static bool flag_start;
static bool flag_pause;
static bool flag_reset;
static bool flag_update;
static bool flag_record;

static uint32_t time_pause;
static uint32_t time_pause_sum;
static uint32_t time_start;
static uint32_t time_stop;

static void init(void *data)
{
	tmos_memset(record, 0, 8 * 4);
	flag_start = false;
	flag_update = false;
	flag_record = false;
	flag_reset = false;
	flag_pause = false;
	time_pause_sum = 0;
	time_pause = 0;
	id = 0;

}

static void dispMs(uint32_t ms)
{
	char buffer[15];

	uint16_t x, y;
//    UG_FillFrame(0, 0, 128, 25, C_BLACK);
	UG_FontSelect(FONT_12X16);
	UG_SetBackcolor(C_BLACK);
	UG_SetForecolor(C_SNOW);
	snprintf(buffer, 15, "%02d:%02d:%03d", ms / 1000 / 60, ms / 1000 % 60,
			ms % 1000);
	uint16_t title_width = UG_GetStringWidth(buffer);
	UG_PutString((LCD_W - title_width) / 2, 1, buffer);

}

static void dispRecord(uint8_t index)
{
	char buffer[15];
	UG_FontSelect(FONT_8X12);
	UG_SetBackcolor(C_BLACK);
	UG_SetForecolor(C_DARK_GREEN);
	UG_FontSetTransparency(0);

	snprintf(buffer, 15, "%02d:%02d:%03d", record[index] / 1000 / 60,
			record[index] / 1000 % 60, record[index] % 1000);

	UG_PutString(45, 28 + index * 12, buffer);


}

static void enter(void *data)
{
	UG_FontSetTransparency(0);
	// insert code
	UG_FillScreen(C_BLACK);
	UG_SetBackcolor(C_BLACK);
	UG_SetForecolor(C_SNOW);

	dispMs(0);
	UG_DrawLine(0, 25, 128, 25, C_GREEN);

	UG_FontSelect(FONT_8X12);
	UG_SetForecolor(C_DARK_GREEN);
	for (uint8_t i = 0; i < 8; i++)
	{
		UG_PutChar(i + '1', 10, 28 + i * 12, C_DARK_GREEN, C_BLACK);
		UG_PutString(45, 28 + i * 12, "__:__:___");
	}

	manager_startEvent(222);
	//
	manager_setBusy(false);
}

static void event(void *data)
{

	if (flag_update == true)
	{
		// 开始刷屏
		uint32_t time_consume;

		time_consume = millis() - time_start - time_pause_sum;

		dispMs(time_consume);
	}
	if (flag_record == true)
	{
		flag_record = false;

		record[id] = time_stop - time_start;
		dispRecord(id);
		id++;
		if (id >= 8)
		{
			id = 0;
		}
	}
	if (flag_reset)
	{
		flag_reset = false;
		flag_start = false;
		flag_update = false;
		flag_record = false;
		flag_pause = false;
		time_pause_sum = 0;
		time_pause = 0;
		id = 0;
		dispMs(0);
		UG_FontSelect(FONT_8X12);
		UG_SetForecolor(C_DARK_GREEN);
		for (uint8_t i = 0; i < 8; i++)
		{
			UG_PutChar(i + '1', 10, 28 + i * 12, C_DARK_GREEN, C_BLACK);
			UG_PutString(45, 28 + i * 12, "__:__:___");
		}

	}

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

	case KEY1_DOWN:

		if (flag_start == false)
		{
			//first
			time_start = millis();
			flag_start = true;
			flag_update = true;
			flag_record = false;

		}
		else
		{
			if (flag_pause == false)
			{
				flag_record = true;
				time_stop = millis() - time_pause_sum;
			}
			else
			{
				time_pause_sum = millis() - time_pause + time_pause_sum;

				flag_pause = false;
				flag_update = true;

			}
		}
		break;

         //pause
	case KEY2_DOWN:
		flag_update = false;
		flag_pause = true;

		time_pause = millis();
		break;

		//reset
	case KEY3_DOWN:

		flag_reset = true;
		break;

	default:
		break;
	}

}

static void quit(void *data)
{
	// insert code
	manager_stopEvent();
	manager_setBusy(true);
}

#include "img.h"
page_t page_stopwatch =
{ .init = init, .enter = enter, .exit = quit, .loop = loop, .event = event,
		.title_en = "stopwatch", .title_cn = "秒表", .icon = img_bits,
		.icon_width = img_width, .icon_height = img_height, .sleep_enable =
		false, .wakeup_btn_effect_enable = false, .acc_enable =
		false,

};
