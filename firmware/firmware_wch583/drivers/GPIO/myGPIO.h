/*
 * myGPIO.h
 *
 *  Created on: Feb 5, 2023
 *      Author: qwert
 */

#ifndef DRIVERS_GPIO_MYGPIO_H_
#define DRIVERS_GPIO_MYGPIO_H_

#include "CH58x_common.h"

 void pinMode(uint8_t pin, GPIOModeTypeDef mode);

int digitalRead(uint8_t pin);

#endif /* DRIVERS_GPIO_MYGPIO_H_ */
