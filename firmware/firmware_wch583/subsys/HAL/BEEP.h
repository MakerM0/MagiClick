/*
 * BEEP.h
 *
 *  Created on: Feb 3, 2023
 *      Author: qwert
 */

#ifndef SUBSYS_HAL_BEEP_H_
#define SUBSYS_HAL_BEEP_H_

#include "CH58x_common.h"
#include "config.h"

#define BEEP_GO_EVT              0x0001
#define BEEP_STOP_EVT            0x0002
#define BEEP_SHOCK_EVT           0x0004
#define BEEP_TEST_EVT            0x0008

#define SHOCK_TIME_MS              50

#define BEEP_ENBALE()          GPIOA_SetBits(GPIO_Pin_12),    \
                                GPIOA_ModeCfg(GPIO_Pin_12, GPIO_ModeOut_PP_5mA)
#define BEEP_DISABLE()         GPIOA_ResetBits(GPIO_Pin_12),   \
                                GPIOB_ModeCfg(GPIO_Pin_12, GPIO_ModeOut_PP_5mA)



extern uint8_t BEEP_TaskID;

void BEEP_Task_Init(void);

#endif /* SUBSYS_HAL_BEEP_H_ */
