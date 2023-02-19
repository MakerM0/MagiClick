/*
 * BEEP.c
 *
 *  Created on: Feb 3, 2023
 *      Author: qwert
 */



#include "BEEP.h"


uint8_t BEEP_TaskID = INVALID_TASK_ID;



//发出不同声调
//percent:0-100
static void BEEP_Tone(uint8_t percent)
{
    if(percent>=100 )percent =99;
    if(percent ==0)
    {
        PWMX_ACTOUT(CH_PWM4, 0, High_Level , DISABLE);  // 25% 占空比
    }
    else
    {
        //1100hz
        PWMX_CLKCfg(213);                                   // cycle = 4/Fsys
        PWMX_CycleCfg(PWMX_Cycle_256);                     // 周期 = 64*cycle
        PWMX_ACTOUT(CH_PWM4, percent * 256 / 100, High_Level, ENABLE);  // 25% 占空比
    }





}



static void BEEP_ProcessTMOSMsg( tmos_event_hdr_t *pMsg )
{
  switch ( pMsg->event )
  {
    case GAP_MSG_EVENT:
    {

      break;
    }

    default:
        break;
  }
}

uint16_t BEEP_ProcessEvent( uint8 task_id, uint16 events )
{
    static bool isgo = false;

    if ( events & SYS_EVENT_MSG ){
      uint8 *pMsg;

      if ( (pMsg = tmos_msg_receive( BEEP_TaskID )) != NULL ){
          BEEP_ProcessTMOSMsg( (tmos_event_hdr_t *)pMsg );
        // Release the TMOS message
        tmos_msg_deallocate( pMsg );
      }
      // return unprocessed events
      return (events ^ SYS_EVENT_MSG);
    }

    if(events & BEEP_GO_EVT){
        if(!isgo){
//            LOG_INFO("drv go!");
            BEEP_ENBALE();

            BEEP_Tone(25);

            isgo = true;
        }
        return (events ^ BEEP_GO_EVT);
    }

    if(events & BEEP_STOP_EVT){
        if(isgo){
//            LOG_INFO("drv stop");
            BEEP_Tone(0);
            BEEP_DISABLE();
            isgo = false;
        }
        return (events ^ BEEP_STOP_EVT);
    }

    if(events & BEEP_SHOCK_EVT){
//        LOG_INFO("drv shock!");
        tmos_start_task(BEEP_TaskID, BEEP_GO_EVT, MS1_TO_SYSTEM_TIME(1));
        tmos_start_task(BEEP_TaskID, BEEP_STOP_EVT, MS1_TO_SYSTEM_TIME(1 + SHOCK_TIME_MS));
        return (events ^ BEEP_SHOCK_EVT);
    }

    if(events & BEEP_TEST_EVT){
        if(!isgo){
            tmos_set_event(BEEP_TaskID, BEEP_GO_EVT);
        }else {
            tmos_set_event(BEEP_TaskID, BEEP_STOP_EVT);
        }
        tmos_start_task(BEEP_TaskID, BEEP_TEST_EVT, MS1_TO_SYSTEM_TIME(1000));
        return (events ^ BEEP_TEST_EVT);
    }

    return 0;
}

void BEEP_Task_Init(void) {

    BEEP_TaskID = TMOS_ProcessEventRegister( BEEP_ProcessEvent );


    tmos_start_task(BEEP_TaskID, BEEP_SHOCK_EVT, MS1_TO_SYSTEM_TIME(200));
}
