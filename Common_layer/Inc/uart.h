/*
 * uart.h
 *
 *  Created on: May 29, 2026
 *      Author: ksree
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "main.h"

extern UART_HandleTypeDef huart2;

void UART_Print(const char *msg);
void MY_USART2_UART_Init(void);

#endif /* INC_UART_H_ */
