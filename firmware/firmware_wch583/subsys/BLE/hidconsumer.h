/********************************** (C) COPYRIGHT *******************************
 * File Name          : hidconsumer.h
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2018/12/13
 * Description        :
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

#ifndef HIDCONSUMER_H
#define HIDCONSUMER_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************************************************************
 * INCLUDES
 */

/*********************************************************************
 * CONSTANTS
 */

// Task Events
#define START_DEVICE_EVT          0x0001
#define START_REPORT_EVT          0x0002
#define START_PARAM_UPDATE_EVT    0x0004
#define START_PHY_UPDATE_EVT      0x0008
/*********************************************************************
 * MACROS
 */

/*
 *
 * hidconsumerservice.c
0x09,0xea,//音量降低
0x09,0xe9,//音量升高
0x09,0xe2,//静音
0x09,0xcd,//播放/暂停
0x09,0xb5,//下一首
0x09,0xb6,//上一首

*/
typedef enum{
    VOL_DOWN=0x01,
    VOL_UP = 0x02,
    VOL_MUTE = 0x04,
    MUSIC_PLAYPAUSE =0x08,
    MUSIC_NEXT = 0x10,
    MUSIC_PREV = 0x20,
}music_ctl_type_t;

/*********************************************************************
 * FUNCTIONS
 */

/*********************************************************************
 * GLOBAL VARIABLES
 */
extern uint8_t hidEmuTaskId;
/*
 * Task Initialization for the BLE Application
 */
extern void HidEmu_Init(void);

/*
 * Task Event Processor for the BLE Application
 */
extern uint16_t HidEmu_ProcessEvent(uint8_t task_id, uint16_t events);
void hidEmuSendConsumerReport(uint8_t volume_up, uint8_t volume_dowm);
/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif
