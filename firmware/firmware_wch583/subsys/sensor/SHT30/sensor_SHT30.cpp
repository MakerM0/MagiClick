/*
 * sensor_SHT30.cpp
 *
 *  Created on: Feb 15, 2023
 *      Author: qwert
 */
#include "sensor_SHT30.h"


extern "C"
{

#include "CH58x_common.h"
}



Adafruit_SHT31 sht;

bool setupSHT30()
{

	Wire.begin();


	if (sht.begin(0x44)) // Set to 0x45 for alternate i2c addr
	{

	}
	else
	{
		return false;
	}
	return true;
}


bool readSHT30(void)
{
	if(sht.readTempHum())
	{

		  return TRUE;
	}
	return FALSE;
}
