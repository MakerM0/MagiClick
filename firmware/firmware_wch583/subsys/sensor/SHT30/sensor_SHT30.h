/*
 * sensor_SHT30.h
 *
 *  Created on: Feb 15, 2023
 *      Author: qwert
 */

#ifndef SUBSYS_SENSOR_SHT30_SENSOR_SHT30_H_
#define SUBSYS_SENSOR_SHT30_SENSOR_SHT30_H_
#include "Adafruit_SHT31.h"
#include <stdint.h>

#define delay(x) DelayMs(x)

extern Adafruit_SHT31 sht;
bool setupSHT30(void);


bool readSHT30(void);




#endif /* SUBSYS_SENSOR_SHT30_SENSOR_SHT30_H_ */
