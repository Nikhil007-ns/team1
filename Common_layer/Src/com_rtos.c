/*
 * com_rtos.c
 *
 *  Created on: Jun 4, 2026
 *      Author: ksree
 */

#include "main.h"
#include"com_freertos.h"
OSThreadID_t MY_OSThreadNew (OSThreadFunc_t func, void *argument, const OSThreadAttr_t *attr)
{
  return osThreadNew(func, argument, attr);
}
