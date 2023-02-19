#include "clock.h"



static void init(void *data)
{

}

#include "HAL/RTC.h"
static void dispTime(bool first)
{
	static bool f_switch = false;
	char buffer[50];
	strftime(buffer, 100, "%F %T", mytime);
	PRINT("time: %s\n", buffer);

	uint16_t year = mytime->tm_year + 1900;
	uint16_t yday = mytime->tm_yday;
	uint8_t month = mytime->tm_mon + 1;
	uint8_t week = mytime->tm_wday + 1;
	uint8_t day = mytime->tm_mday;
	uint8_t hour = mytime->tm_hour;
	uint8_t minute = mytime->tm_min;
	uint8_t second = mytime->tm_sec;

	static uint16_t year_l = 0;
	static uint16_t yday_l = 0;
	static uint8_t month_l = 0;
	static uint8_t week_l = 0;
	static uint8_t day_l = 0;
	static uint8_t hour_l = 0;
	static uint8_t minute_l = 0;
	static uint8_t second_l = 0;
	if (first)
	{
		UG_FontSelect(FONT_32X53);
		UG_SetBackcolor(C_BLACK);

		UG_SetForecolor(C_CORN_SILK);
		snprintf(buffer, 15, "%02d ", hour);

		UG_PutString(32, 10, buffer);

		UG_SetForecolor(C_BLUE_VIOLET);
		snprintf(buffer, 15, "%02d ", minute);

		UG_PutString(32, 70, buffer);

		UG_FillFrame(115 - 4, 64 - 4, 115 + 4, 64 + 4, C_GREEN_YELLOW);
		f_switch = true;
	}
	else
	{
		if ((year ^ year_l) || (yday ^ yday_l) || (month ^ month_l)
				|| (week ^ week_l) || (day ^ day_l) || (hour ^ hour_l)
				|| (minute ^ minute_l))
		{
			uint32_t starttime = millis();

			UG_SetForecolor(C_CORN_SILK);
			snprintf(buffer, 15, "%02d ", hour);

			UG_PutString(32, 10, buffer);

			UG_SetForecolor(C_BLUE_VIOLET);
			snprintf(buffer, 15, "%02d ", minute);

			UG_PutString(32, 70, buffer);

			LOG_INFO("time: %d ms!", millis() - starttime);
		}
		if (second ^ second_l)
		{
			if (f_switch == true)
			{
				UG_FillFrame(115 - 4, 64 - 4, 115 + 4, 64 + 4, C_DARK_GREEN);
//                UG_FillCircle(115, 64, 4, C_DARK_GREEN);
			}
			else
			{
				UG_FillFrame(115 - 4, 64 - 4, 115 + 4, 64 + 4, C_GREEN_YELLOW);
//                UG_FillCircle(115, 64, 8, C_GREEN_YELLOW);
			}
			f_switch = !f_switch;
		}

	}

	year_l = year;
	yday_l = yday;
	month_l = month;
	week_l = week;
	day_l = day;
	hour_l = hour;
	minute_l = minute;
	second_l = second;
}

static void enter(void *data)
{
	// insert code
	UG_FillScreen(C_BLACK);
	UG_FontSetTransparency(0);

	dispTime(true);
	manager_startEventOnce(0);
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
	dispTime(false);
	manager_startEventOnce(1000);

}
static void quit(void *data)
{

	manager_stopEvent();
	UG_FontSetTransparency(1);
	manager_setBusy(true);
}
#include "img.h"
page_t page_clock =
{ .init = init, .enter = enter, .exit = quit, .loop = loop, .event = event,
		.title_en = "clock", .title_cn = "时间", .icon = img_bits, .icon_width =
				img_width, .icon_height = img_height, .sleep_enable =
		false, .wakeup_btn_effect_enable = false, .acc_enable = false,

};
