#include "LCD_show/show_task.h"
#include "HAL/HAL.h"
#include "SPI/mySPI.h"
#include "HAL/RTC.h"
#include <time.h>
//#include "ST7735S/pic.h"
//#include "ST7735S/lcd.h"
//#include "ST7735S/lcd_init.h"

#include <string.h>
#include "GC9107/lcd.h"
//#include "GC9107/lcd_init.h"
//#include "UGUI/ugui.h"
//#include "GC9107/pic.h"
#include "img/loading.h"
#include "img/shutter.h"
#include "img/ble_connected.h"
#include "img/ble_unconnected.h"
#include "img/charge.h"
#include "img/clock.h"
#include "ug.h"

uint8_t show_TaskID = INVALID_TASK_ID;

static void Show_ProcessTMOSMsg(tmos_event_hdr_t *pMsg)
{
	switch (pMsg->event)
	{
	case GAP_MSG_EVENT:
	{

		break;
	}

	case SHOW_SHT_EVT:
	{

		if (strcmp(manager.cur->title_en, "Temper&Humi") == 0)
		{
			uint16_t temp_forecolor = C_DARK_GREEN;
			uint16_t temp_bgcolor = C_BLACK;

			uint16_t humi_forecolor = C_DARK_SLATE_BLUE;
			uint16_t humi_bgcolor = C_LIGHT_GRAY;


			SendMSG_t *msg = (SendMSG_t *) pMsg;
			//扩大十倍
			float temperature = (*((float*) (msg->pData))) * 10;
			float humidity = (*((float*) (msg->pData + 4))) * 10;
			char buffer[15];





			UG_FontSetTransparency(false);


			//temper
			UG_SetBackcolor(temp_bgcolor);

			UG_FontSelect(FONT_32X53);
			UG_SetForecolor(temp_forecolor);
			sprintf(buffer, "%d", ((int) temperature) / 10);
			UG_PutString(18, 4, buffer);


			UG_FontSelect(FONT_22X36);
			UG_SetForecolor(temp_forecolor);

			sprintf(buffer, "%d", ((int) temperature)% 10);
			UG_PutString(89, 21, buffer);

//			UG_FontSelect(FONT_12X16);
//			UG_PutChar('C', 99, 4, C_WHITE, C_BLACK);

			//humi

			UG_SetBackcolor(humi_bgcolor);

			UG_FontSelect(FONT_32X53);
			UG_SetForecolor(humi_forecolor);
			sprintf(buffer, "%d", ((int) humidity) / 10);
			UG_PutString(18, 70, buffer);

			UG_FontSelect(FONT_22X36);
			UG_SetForecolor(humi_forecolor);

			sprintf(buffer, "%d", ((int) humidity)% 10);
			UG_PutString(89, 87, buffer);

//			UG_FontSelect(FONT_12X16);
//			UG_PutChar('%', 99, 70, C_BLACK, C_WHITE);


			UG_FontSetTransparency(true);
//			LCD_ShowFloatNum1(0, 0, temperature, 5, WHITE, BLACK, 16);
//			LCD_ShowFloatNum1(0, 20, humidity, 5, WHITE, BLACK, 16);
		}

	}
		break;



	case SHOW_TIME_EVT:
	{
		tmos_set_event(show_TaskID, SHOW_TIME_EVENT);
	}
		break;

	default:
		break;
	}
}

uint16_t Show_ProcessEvent(uint8 task_id, uint16 events)
{
	if (events & SYS_EVENT_MSG)
	{
		uint8 *pMsg;

		if ((pMsg = tmos_msg_receive(show_TaskID)) != NULL)
		{
			Show_ProcessTMOSMsg((tmos_event_hdr_t *) pMsg);
			// Release the TMOS message
			tmos_msg_deallocate(pMsg);
		}
		// return unprocessed events
		return (events ^ SYS_EVENT_MSG);
	}
	if (events & SHOW_MANAGER_LOOP_EVENT)
	{
		manager_loop();
		tmos_start_task(show_TaskID, SHOW_MANAGER_LOOP_EVENT,
				MS1_TO_SYSTEM_TIME(30));

		return (events ^ SHOW_MANAGER_LOOP_EVENT);
	}

	if (events & SHOW_MANAGER_EVT_EVENT)
	{
		manager_event();
//            tmos_start_task(show_TaskID, SHOW_MANAGER_EVT_EVENT, MS1_TO_SYSTEM_TIME(20));

		return (events ^ SHOW_MANAGER_EVT_EVENT);
	}

	if (events & SHOW_SWITCH_PAGES_EVENT)
	{
		switchpages();
		return (events ^ SHOW_SWITCH_PAGES_EVENT);
	}

	if (events & SHOW_TEST_EVENT)
	{
//        LCD_Showtest(0, 0, LCD_W, LCD_H);

//        LCD_ShowPicture(0, 0, 0x50, 0x94, gImage_spring);
//        LCD_ShowPicture(10, 10, 0x50, 0x94, gImage_321);

		static uint8_t pic = 1;
		uint32_t start = millis();

		LCD_ShowPicture(0, 0, 128, 128, gImage_loading);
//        LCD_ShowString(33, 40, "wch", WHITE, BLACK, 16, 1);
//        SHOW_FUN(1);
		PRINT("show time %d ms\n", millis() - start);
		return (events ^ SHOW_TEST_EVENT);
	}

	return 0;
}

void Show_Task_Init(void)
{
	show_TaskID = TMOS_ProcessEventRegister(Show_ProcessEvent);

	MySPIinit();
	ug_init();
	LCD_ShowPicture(0, 0, 128, 128, gImage_loading);
	LCD_BLK_Set(); //打开背光
	DelayMs(1000);
	manager_init();

	tmos_start_task(show_TaskID, SHOW_MANAGER_LOOP_EVENT,
			MS1_TO_SYSTEM_TIME(500));

//    tmos_set_event(show_TaskID, SHOW_STR_TIME_EVENT);
//    tmos_set_event(show_TaskID, SHOW_PIC_EVENT);
//    tmos_start_reload_task(show_TaskID, SHOW_TEST_EVENT, MS1_TO_SYSTEM_TIME(500));
}
