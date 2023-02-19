#include "sensor_task.h"
#include "sensor/SHT30/sensor_SHT30.h"
extern "C"
{
#include "config.h"
#include <stdint.h>
#include "HAL/HAL.h"
#include "LCD_show/show_task.h"

}

uint8_t Sensor_TaskID = INVALID_TASK_ID;

static uint32_t last_time = millis();

static void Sensor_ProcessTMOSMsg(tmos_event_hdr_t *pMsg)
{
	switch (pMsg->event)
	{
	case GAP_MSG_EVENT:
	{

		break;
	}


	default:
		break;
	}
}

uint16_t Sensor_ProcessEvent(uint8 task_id, uint16 events)
{
	if (events & SYS_EVENT_MSG)
	{
		uint8 *pMsg;

		if ((pMsg = tmos_msg_receive(Sensor_TaskID)) != NULL)
		{
			Sensor_ProcessTMOSMsg((tmos_event_hdr_t *) pMsg);
			// Release the TMOS message
			tmos_msg_deallocate(pMsg);
		}
		// return unprocessed events
		return (events ^ SYS_EVENT_MSG);
	}


	if(events & SHT30_EVENT)
	{
		static float data[2] ;
		if(readSHT30())
		{
			data[0] = sht.temp;
			data[1] = sht.humidity;
//			LCD_ShowString(0, 80, (const unsigned char *)"00", WHITE, BLACK, 16, 1);
//			LCD_ShowString(0, 40, (const unsigned char *)"ok", WHITE, BLACK, 16, 1);
//			LCD_ShowFloatNum1(50, 0, data[0], 5, WHITE, BLACK, 16);
//			LCD_ShowFloatNum1(50, 20, data[1], 5, WHITE, BLACK, 16);
			OnBoard_SendMsg(show_TaskID, SHOW_SHT_EVT, 1, data);
		}
		else {
//			LCD_ShowString(0, 80, (const unsigned char *)"xx", WHITE, BLACK, 16, 1);
		}

		tmos_start_task(Sensor_TaskID, SHT30_EVENT, MS1_TO_SYSTEM_TIME(500));
		return (events ^ SHT30_EVENT);
	}


	return 0;
}

void Sensor_Task_Init(void)
{

	Sensor_TaskID = TMOS_ProcessEventRegister(Sensor_ProcessEvent);

	if(setupSHT30())
	{
//		LCD_ShowString(0, 0, (const unsigned char *)"ok", WHITE, BLACK, 16, 1);
		tmos_start_task(Sensor_TaskID, SHT30_EVENT, MS1_TO_SYSTEM_TIME(100));
	}

}

