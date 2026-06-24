/*
 * com_rtos.c
 *
 *  Created on: Jun 4, 2026
 *      Author: ASUS
 */
#include "cmsis_os2.h"
#include"com_rtos.h"

OsThreadId_t My_osThreadNew(OsThreadFunc_t func, void *argument, const OSThreadAttr_t *attr)
{
  //return osThreadNew ( func, NULL, &lcdTask_attributes);
	return osThreadNew(func, argument, attr);
}
