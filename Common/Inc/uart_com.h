/*
 * uart_com.c
 *
 *  Created on: May 30, 2026
 *      Author: user
 */

#ifndef INC_UART_COM_C_
#define INC_UART_COM_C_

#include <stdint.h>
#include "main.h"


typedef UART_HandleTypeDef        uart_handletypedef;
typedef HAL_StatusTypeDef		 StatusTypeDef;

extern uart_handletypedef huart1;
//#define  uart_handletypedef      UART_HandleTypeDef
//#define  StatusTypeDef            HAL_StatusTypeDef



//typedef struct uarthandle
//{
//	 UART_HandleTypeDef *uart;
//
//}_uarthandle;


//extern uart_handletypedef huart1;
//extern uart_handletypedef huart5;

void MY_USART1_UART_Init(void);

StatusTypeDef UART1_Transmit(uart_handletypedef *huart1, const uint8_t *pData, uint16_t Size, uint32_t Timeout   );
StatusTypeDef  UART1_Receive(uart_handletypedef *huart1 , uint8_t *pData, uint16_t Size, uint32_t Timeout);

#endif /* INC_UART_COM_C_ */
