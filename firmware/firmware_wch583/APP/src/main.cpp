extern "C"
{
#include "CH58x_common.h"
#include "HAL/config.h"
#include "HAL/HAL.h"
#include "HAL_FLASH/include/easyflash.h"

#include "LCD_show/show_task.h"

#include "BLE/dfu.h"
#include "BLE/CTS.h"

#include "BLE/hidconsumer.h"
#include "BLE/profile/hiddev.h"
}

#include "sensor/sensor_task.h"

#include "HAL/BEEP.h"

/*********************************************************************
 * GLOBAL TYPEDEFS
 */
__attribute__((aligned(4)))   u32 MEM_BUF[BLE_MEMHEAP_SIZE / 4];

#if (defined (BLE_MAC)) && (BLE_MAC == TRUE)
uint8_t MacAddr[6] =
{ 0x84, 0xC2, 0xE4, 0x03, 0x02, 0x32 };
#endif

/*******************************************************************************
 * Function Name  : Main_Circulation
 * Description    : 主循环
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
__attribute__((section(".highcode")))
void Main_Circulation()
{
	while(1)
	{
		TMOS_SystemProcess( );
	}
}

/*******************************************************************************
 * Function Name  : main
 * Description    : 主函数
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
int main(void)
{
	/*enable systick interrupt     */
	SysTick_Config(FREQ_SYS / 1000);  //1ms

#if (defined (DCDC_ENABLE)) && (DCDC_ENABLE == TRUE)
	PWR_DCDCCfg(ENABLE);
#endif

//  GPIOA_ModeCfg( GPIO_Pin_All, GPIO_ModeIN_PD );
//  GPIOB_ModeCfg( GPIO_Pin_All, GPIO_ModeIN_PD );
#ifdef DEBUG
	GPIOA_SetBits(bTXD1);
	GPIOA_ModeCfg(bTXD1, GPIO_ModeOut_PP_5mA);
	UART1_DefInit();
#endif
	PRINT("123\r\n");
	DEBUG_Init();

	GPIOA_ModeCfg(GPIO_Pin_5, GPIO_ModeIN_Floating);
	if (GPIOA_ReadPortPin(GPIO_Pin_5) == 0)
	{
		DelayMs(500);
		if (GPIOA_ReadPortPin(GPIO_Pin_5) == 0)
		{
			GPIOA_SetBits(GPIO_Pin_4);
			GPIOA_ModeCfg(GPIO_Pin_4, GPIO_ModeOut_PP_5mA);
		}
		else
		{
			GPIOA_ResetBits(GPIO_Pin_4);
			GPIOA_ModeCfg(GPIO_Pin_4, GPIO_ModeOut_PP_5mA);
			DelayMs(100);
		}
	}

	/*DataFlash初始化*/
	if (easyflash_init() != SUCCESS)
	{
		LOG_INFO("Date Flash init error!");
	}
	ef_print_env();

	CH58X_BLEInit();
	HAL_Init();
	BEEP_Task_Init();
	Show_Task_Init();

	Sensor_Task_Init();

	GAPRole_PeripheralInit();
	HidDev_Init();
	HidEmu_Init();

	CurrentTime_Init();
//  dfu_Init();

	Main_Circulation();
}

