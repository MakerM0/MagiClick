/********************************** (C) COPYRIGHT *******************************
* File Name          : KEY.h
* Author             : WCH
* Version            : V1.0
* Date               : 2016/04/12
* Description        : 
*******************************************************************************/



/******************************************************************************/
#ifndef __KEY_H
#define __KEY_H

#include "CH58xBLE_LIB.h"
#include "RingBuffer/lwrb.h"



#ifdef __cplusplus
extern "C"
{
#endif

extern lwrb_t buff_key;
#define BUFF_KEY_NUM 16



typedef enum
{
    KEY_NONE = 0,


    KEY1_DOWN,   //  按下
        KEY1_UP,     //  释放
        KEY1_SHORT,  //  短按
        KEY1_LONG,   //  长按
        KEY1_DOUBLE, //  双击
        KEY1_TRIPLE, //  三击

        KEY2_DOWN,   //  按下
            KEY2_UP,     //  释放
            KEY2_SHORT,  //  短按
            KEY2_LONG,   //  长按
            KEY2_DOUBLE, //  双击
            KEY2_TRIPLE, //  三击

            KEY3_DOWN,   //  按下
                KEY3_UP,     //  释放
                KEY3_SHORT,  //  短按
                KEY3_LONG,   //  长按
                KEY3_DOUBLE, //  双击
                KEY3_TRIPLE, //  三击

} KEY_TYPE;



#define KEY_CHANGE                   0xC0    // Key message

#define HAL_KEY_RISING_EDGE            0
#define HAL_KEY_FALLING_EDGE           1

#define HAL_KEY_DEBOUNCE_VALUE         25
#define HAL_KEY_POLLING_VALUE          MS1_TO_SYSTEM_TIME(100)

/* Interrupt option - Enable or disable */
#define HAL_KEY_INTERRUPT_DISABLE    0x00
#define HAL_KEY_INTERRUPT_ENABLE     0x01

/* Key state - shift or nornal */
#define HAL_KEY_STATE_NORMAL         0x00
#define HAL_KEY_STATE_SHIFT          0x01



/**************************************************************************************************
 * TYPEDEFS
 **************************************************************************************************/
typedef void (*halKeyCBack_t) (uint8_t keys, uint8_t state);

typedef struct
{
  tmos_event_hdr_t hdr;
  uint8_t  state; // shift
  uint8_t  keys;  // keys
} keyChange_t;

/**************************************************************************************************
 *                                             GLOBAL VARIABLES
 **************************************************************************************************/
extern uint8_t Hal_KeyIntEnable;

/*********************************************************************
 * FUNCTIONS
 */

/*
 * Initialize the Key Service
 */
void HAL_KeyInit( void );

/*
 * This is for internal used by hal_driver
 */
void HAL_KeyPoll( void );

/*
 * Register the Key Service
 */
void HAL_KEY_RegisterForKeys( tmosTaskID id );

/*
 * Configure the Key Service
 */
void HalKeyConfig( uint8_t interruptEnable, const halKeyCBack_t cback);

/*
 * Read the Key callback
 */
void HalKeyCallback ( uint8_t keys, uint8_t state );

/*
 * Read the Key status
 */
uint8_t HalKeyRead( void);

KEY_TYPE HAL_KeyGet();

int IsKeyDown1();

int IsKeyDown2();

int IsKeyDown3();

/**************************************************************************************************
**************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif
