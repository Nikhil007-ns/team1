/*
 * uart_com.c
 *
 *  Created on: May 30, 2026
 *      Author: user
 */


#include "main.h"
#include "uart_com.h"

uart_handletypedef huart1;
uart_handletypedef huart5;


StatusTypeDef UART1_Transmit(uart_handletypedef *huart1 , const uint8_t *pData, uint16_t Size, uint32_t Timeout   )
{
	return HAL_UART_Transmit(huart1, pData, Size, Timeout);
}

StatusTypeDef  UART1_Receive(uart_handletypedef *huart1, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{

	return HAL_UART_Receive( huart1  ,pData, Size, Timeout);

}






 void MY_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

