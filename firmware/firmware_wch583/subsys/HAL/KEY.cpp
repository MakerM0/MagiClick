/********************************** (C) COPYRIGHT *******************************
 * File Name          : KEY.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2014/05/12
 * Description        :
 *******************************************************************************/

/******************************************************************************/
/* 头文件包含 */
#include "CH58x_common.h"
#include "HAL/HAL.h"

#include "Button2/Button2.h"
Button2 button1;
Button2 button2;
Button2 button3;

uint8 Hal_KeyIntEnable; /* interrupt enable/disable flag */

// Registered keys task ID, initialized to NOT USED.
static uint8 registeredKeysTaskID = TASK_NO_TASK;
static uint8 halKeySavedKeys; /* 保留按键最后的状态，用于查询是否有键值变化 */
static uint8 KeyConfigFlag; /* 按键是否配置标志位 */

/**************************************************************************************************
 *                                        FUNCTIONS - Local
 **************************************************************************************************/
static halKeyCBack_t pHalKeyProcessFunction; /* callback function */

lwrb_t buff_key;
static uint8_t buff_data[BUFF_KEY_NUM];

/////////////////////////////////////////////////////////////////
static KEY_TYPE key_type;
extern "C"
{
#include "LCD_show/GC9107/lcd.h"
}
void click(Button2& btn)
{
	if (btn == button1)
	{
		PRINT("click 1 \r\n");
		key_type = KEY1_SHORT;
		lwrb_write(&buff_key, &key_type, 1);

	}
	else if (btn == button2)
	{
		PRINT("click 2 \r\n");
		key_type = KEY2_SHORT;
		lwrb_write(&buff_key, &key_type, 1);

	}
	else if (btn == button3)
	{
		PRINT("click 3 \r\n");
		key_type = KEY3_SHORT;
		lwrb_write(&buff_key, &key_type, 1);

	}
}

void pressed(Button2& btn)
{
	if (btn == button1)
	{
		PRINT("down 1 \r\n");
		key_type = KEY1_DOWN;
		lwrb_write(&buff_key, &key_type, 1);

	}
	else if (btn == button2)
	{
		PRINT("down 2 \r\n");
		key_type = KEY2_DOWN;
		lwrb_write(&buff_key, &key_type, 1);

	}
	else if (btn == button3)
	{
		PRINT("down 3 \r\n");
		key_type = KEY3_DOWN;
		lwrb_write(&buff_key, &key_type, 1);

	}
}
void doubleClick(Button2& btn)
{
	if (btn == button1)
	{
		key_type = KEY1_DOUBLE;
		lwrb_write(&buff_key, &key_type, 1);
	}
	else if (btn == button2)
	{
		key_type = KEY2_DOUBLE;
		lwrb_write(&buff_key, &key_type, 1);
	} else if (btn == button3)
	{
		key_type = KEY3_DOUBLE;
		lwrb_write(&buff_key, &key_type, 1);
	}
}
void tripleClick(Button2& btn)
{
	if (btn == button1)
	{
		key_type = KEY1_TRIPLE;
		lwrb_write(&buff_key, &key_type, 1);
	}else if (btn == button2)
	{
		key_type = KEY2_TRIPLE;
		lwrb_write(&buff_key, &key_type, 1);
	}
	else if (btn == button3)
		{
			key_type = KEY3_TRIPLE;
			lwrb_write(&buff_key, &key_type, 1);
		}
}
void longClick(Button2& btn)
{
	unsigned int time = btn.wasPressedFor();

	if (btn == button1)
	{
		key_type = KEY1_LONG;
		lwrb_write(&buff_key, &key_type, 1);
//        PRINT("You clicked ");
//        if (time > 1500)
//        {
//            key_type = KEY1_LONG;
//            lwrb_write(&buff_key, &key_type, 1);
//            PRINT("a really really long time.");
//        } else if (time > 1000)
//        {
//            key_type = KEY1_LONG;
//            lwrb_write(&buff_key, &key_type, 1);
//            PRINT("a really long time.");
//        } else if (time > 500)
//        {
//            key_type = KEY1_LONG;
//            lwrb_write(&buff_key, &key_type, 1);
//            PRINT("a long time.");
//        } else {
//            PRINT("long.");
//        }
//        PRINT(" (");
//        PRINT("%d",time);
//        PRINT(" ms\r\n)");
	}
	else if (btn == button2)
	{
		key_type = KEY2_LONG;
		lwrb_write(&buff_key, &key_type, 1);
		PRINT("You clicked ");
//                if (time > 1500)
//                {
//                    PRINT("a really really long time.");
//                } else if (time > 1000)
//                {
//                    PRINT("a really long time.");
//                } else if (time > 500)
//                {
//
//                    PRINT("a long time.");
//                } else {
//                    PRINT("long.");
//                }
//                PRINT(" (");
//                PRINT("%d",time);
//                PRINT(" ms\r\n)");

	}
	else if (btn == button3)
	{
		key_type = KEY3_LONG;
		lwrb_write(&buff_key, &key_type, 1);
//        PRINT("You clicked ");
//                if (time > 1500)
//                {
//                    PRINT("a really really long time.");
//                } else if (time > 1000)
//                {
//                    PRINT("a really long time.");
//                } else if (time > 500)
//                {
//
//                    PRINT("a long time.");
//                } else {
//                    PRINT("long.");
//                }
//                PRINT(" (");
//                PRINT("%d",time);
//                PRINT(" ms\r\n)");

	}
}

void longClickDetected(Button2& btn)
{
//    PRINT("long click #");
//    PRINT("%d",btn.getLongClickCount());
//    PRINT(" detected\r\n");
	tmos_set_event(BEEP_TaskID, BEEP_SHOCK_EVT);
}
KEY_TYPE HAL_KeyGet()
{
	uint8_t data = KEY_NONE;
	size_t len = lwrb_read(&buff_key, &data, 1);

	if (len == 0)
	{
		return KEY_NONE;
	}
	return (KEY_TYPE) data;

}
int IsKeyDown1()
{
	return (GPIOB_ReadPortPin(GPIO_Pin_14) > 0) ? 1 : 0;
}

int IsKeyDown2()
{
	return (GPIOA_ReadPortPin(GPIO_Pin_5) > 0) ? 1 : 0;
}

int IsKeyDown3()
{
	return (GPIOB_ReadPortPin(GPIO_Pin_22) > 0) ? 1 : 0;
}

/**************************************************************************************************
 * @fn      HAL_KeyInit
 *
 * @brief   Initilize Key Service
 *
 * @param   none
 *
 * @return  None
 **************************************************************************************************/
void HAL_KeyInit(void)
{

	/* Initialize previous key to 0 */
	halKeySavedKeys = 0;
	/* Initialize callback function */
	pHalKeyProcessFunction = NULL;
	/* Start with key is not configured */
	KeyConfigFlag = FALSE;

	lwrb_init(&buff_key, buff_data, sizeof(buff_data)); /* Initialize buffer */

	button1.begin(14 + 32, GPIO_ModeIN_PU, true);
	button2.begin(5 + 0, GPIO_ModeIN_PU, true);
	button3.begin(22 + 32, GPIO_ModeIN_PU, true);

	button1.setPressedHandler(pressed);
	button2.setPressedHandler(pressed);
	button3.setPressedHandler(pressed);

	button1.setClickHandler(click);
	button2.setClickHandler(click);
	button3.setClickHandler(click);

	button1.setLongClickHandler(longClick);
	button2.setLongClickHandler(longClick);
	button3.setLongClickHandler(longClick);

	button1.setLongClickDetectedHandler(longClickDetected);
	button2.setLongClickDetectedHandler(longClickDetected);
	button3.setLongClickDetectedHandler(longClickDetected);

	button1.setTripleClickHandler(tripleClick);
	button2.setTripleClickHandler(tripleClick);
	button3.setTripleClickHandler(tripleClick);

	button1.setTripleClickHandler(doubleClick);
	button2.setTripleClickHandler(doubleClick);
	button3.setTripleClickHandler(doubleClick);

	HalKeyConfig(HAL_KEY_INTERRUPT_DISABLE, HalKeyCallback);
	// GPIOB_ITModeCfg(GPIO_Pin_8, GPIO_ITMode_RiseEdge);
	// PFIC_EnableIRQ(GPIO_B_IRQn);
	HAL_KEY_RegisterForKeys(halTaskID);
}

void HAL_KEY_RegisterForKeys(tmosTaskID id)
{
	registeredKeysTaskID = id;
}

/**************************************************************************************************
 * @fn      HalKeyConfig
 *
 * @brief   Configure the Key serivce
 *
 * @param   interruptEnable - TRUE/FALSE, enable/disable interrupt
 *          cback - pointer to the CallBack function
 *
 * @return  None
 **************************************************************************************************/
void HalKeyConfig(uint8 interruptEnable, halKeyCBack_t cback)
{
	/* Enable/Disable Interrupt or */
	Hal_KeyIntEnable = interruptEnable;
	/* Register the callback fucntion */
	pHalKeyProcessFunction = cback;
	/* Determine if interrupt is enable or not */
	if (Hal_KeyIntEnable)
	{
		/* Do this only after the hal_key is configured - to work with sleep stuff */
		if (KeyConfigFlag == TRUE)
		{
			tmos_stop_task(halTaskID, HAL_KEY_EVENT); /* Cancel polling if active */
		}
	}
	else
	{ /* Interrupts NOT enabled */
		tmos_start_task(halTaskID, HAL_KEY_EVENT, HAL_KEY_POLLING_VALUE); /* Kick off polling */
	}
	/* Key now is configured */
	KeyConfigFlag = TRUE;
}

/*********************************************************************
 * @fn      OnBoard_SendKeys
 *
 * @brief   Send "Key Pressed" message to application.
 *
 * @param   keys  - keys that were pressed
 *          state - shifted
 *
 * @return  status
 *********************************************************************/
uint8 OnBoard_SendKeys(uint8 keys, uint8 state)
{
	keyChange_t *msgPtr;

	if (registeredKeysTaskID != TASK_NO_TASK)
	{
		// Send the address to the task
		msgPtr = (keyChange_t *) tmos_msg_allocate(sizeof(keyChange_t));
		if (msgPtr)
		{
			msgPtr->hdr.event = KEY_CHANGE;
			msgPtr->state = state;
			msgPtr->keys = keys;
			tmos_msg_send(registeredKeysTaskID, (uint8 *) msgPtr);
		}
		return (SUCCESS);
	}
	else
	{
		return (FAILURE);
	}
}

/*********************************************************************
 * @fn      OnBoard_KeyCallback
 *
 * @brief   Callback service for keys
 *
 * @param   keys  - keys that were pressed
 *          state - shifted
 *
 * @return  void
 *********************************************************************/
void HalKeyCallback(uint8 keys, uint8 state)
{
	ARG_UNUSED(state);

	if (OnBoard_SendKeys(keys, state) != SUCCESS)
	{

	}
}

/**************************************************************************************************
 * @fn      HalKeyRead
 *
 * @brief   Read the current value of a key
 *
 * @param   None
 *
 * @return  keys - current keys status
 **************************************************************************************************/
uint8 HalKeyRead(void)
{
	uint8 keys = 0;

	return keys;
}

/**************************************************************************************************
 * @fn      HAL_KeyPoll
 *
 * @brief   Called by hal_driver to poll the keys
 *
 * @param   None
 *
 * @return  None
 **************************************************************************************************/
void HAL_KeyPoll(void)
{
//    uint8 keys = 0;
//    bsp_KeyScan();

//    Button_Process();     //需要周期调用按键处理函数

	button1.loop();
	button2.loop();
	button3.loop();

//    PRINT("%d\r\n",GPIOB_ReadPortPin(GPIO_Pin_22));

//    keys = bsp_GetKey();
//    if (keys != KEY_NONE)
//    {
//        if ((pHalKeyProcessFunction))
//        {
//            (pHalKeyProcessFunction)(keys, HAL_KEY_STATE_NORMAL);
//        }
//    }

}

/******************************** endfile @ key ******************************/
