/*
 * ui.h
 *
 *  Created on: Dec 3, 2022
 *      Author: qwert
 */


#ifndef __UG_H
#define __UG_H

#include "UGUI/ugui.h"
#include "UGUI/ugui_config.h"
#include "GC9107/lcd.h"
#include "GC9107/lcd_init.h"
#include "CH58xBLE_LIB.h"

void ug_init();
uint16_t UG_GetStringWidth(char *str);

#endif
