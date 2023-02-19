/*
 * myGPIO.cpp
 *
 *  Created on: Feb 5, 2023
 *      Author: qwert
 */


#include "myGPIO.h"
//pin:0-63,每个port含有32个引脚，PA0-PA15   ,PB0-23
 void pinMode(uint8_t pin, GPIOModeTypeDef mode)
{

    if(pin<32)
    {

        GPIOA_ModeCfg(1<<pin, mode);
    }
    else
    {
        pin=pin-32;
//        PRINT("\r\n pin:%d   0x%08x\r\n",pin,1<<pin);
        GPIOB_ModeCfg(1<<pin, mode);
    }

}

int digitalRead(uint8_t pin)
{

    if(pin<32)
    {

//        return GPIOA_ReadPortPin(1<<pin);
        uint32_t x = (GPIOA_ReadPortPin(1<<pin)!=0)?1:0;
//        PRINT("PA%d:%d  %d\r\n",pin ,x,millis());
                return  x;
    }
    else
    {
        pin=pin-32;
        uint32_t x = (GPIOB_ReadPortPin(1<<pin)!=0)?1:0;
//        PRINT("PB%d:%d  %d\r\n",pin ,x,millis());
        return  x;

    }

}
