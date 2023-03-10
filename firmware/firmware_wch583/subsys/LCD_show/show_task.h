#ifndef __SHOW_TASK_H
#define __SHOW_TASK_H

#include "CH58x_common.h"
#include "config.h"
#include "pages/pages.h"

#define SHOW_HEART_EVENT            0x0001
#define SHOW_PIC_EVENT              0x0002
#define SHOW_TIME_EVENT             0x0004
#define SHOW_STR_SPORT_EVENT            0x0008
#define SHOW_STR_TIME_EVENT             0x0010
#define SHOW_SWITCH_PAGES_EVENT     0x0020
#define SHOW_MANAGER_LOOP_EVENT     0x0040
#define SHOW_MANAGER_EVT_EVENT     0x0080

#define SHOW_TEST_EVENT             0x0800
extern uint8_t show_TaskID;

void Show_Task_Init(void);

#endif
