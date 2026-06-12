/*
 * uart.c
 *
 *  Created on: May 29, 2026
 *      Author: ksree
 */

#include "main.h"
//#include "app_temp.h"
#include "com_gpio.h"
#include "app_keypad.h"
#include "string.h"
#include "uart.h"

//UART_HandleTypeDef huart2;

void UART_Print(const char *msg)
{
    HAL_UART_Transmit(&huart2,
                      (uint8_t *)msg,
                      strlen(msg),
                      200);
}
