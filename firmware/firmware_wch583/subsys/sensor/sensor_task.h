#ifndef __SENSOR_TASK_H
#define __SENSOR_TASK_H

#include "CH58x_common.h"


#define SHT30_EVENT				0x0004

void Sensor_Task_Init(void);
extern uint8_t Sensor_TaskID;

#endif
