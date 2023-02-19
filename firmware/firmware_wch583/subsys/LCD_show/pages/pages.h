#ifndef __PAGES_H
#define __PAGES_H

#include "LCD_show/manager/manager.h"
#include "LCD_show/show_task.h"
#include "HAL/HAL.h"

extern page_t page_main;

extern page_t *pages[];
void switchpages();
#endif
