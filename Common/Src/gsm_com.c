/*
 * gsm_com.c
 *
 *  Created on: May 30, 2026
 *      Author: user
 */

#include "cmsis_os2.h"
#include "string.h"
#include "uart_com.h"
#include "gsm_com.h"

volatile uint32_t  gsm_prev;



extern uart_handletypedef huart1;
extern uart_handletypedef huart5;



void GSM_CONFIG(void)
{

	osDelay(1000);
	Gsm_Send_Cmd((uint8_t*)"AT\r\n");
	osDelay(1000);

	Gsm_Send_Cmd((uint8_t *)"ATE0\r\n");
	osDelay(1000);

	Gsm_Send_Cmd((uint8_t *)"AT+CPIN?\r\n");
	osDelay(1000);

	Gsm_Send_Cmd((uint8_t *)"AT+CSQ\r\n");
	osDelay(1000);

	Gsm_Send_Cmd((uint8_t *)"AT+CREG?\r\n");
	osDelay(1000);





}





void DataToPhone(unsigned char *data)
{
  uint8_t ctrl_z = 0x1A;


		   Gsm_Send_Cmd((uint8_t *)"AT+CMGF=1\r\n");
		   osDelay(1000);
		    Gsm_Send_Cmd((uint8_t *)"AT+CMGS=\"+919482269045\"\r\n");
		    osDelay(1000);

			/*if adc value not converted to string convert string and send*/


//		    _uarthandle handle = {.uart = &huart1};

			UART1_Transmit(&huart1 , data , strlen((const char *)data) , 1000 );
			UART1_Transmit(&huart1, &ctrl_z, 1, 1000);







}

void Gsm_Send_Cmd(unsigned char *cmd)
{
//char rx_data[100];
//	   _uarthandle handle = {.uart = &huart1};
UART1_Transmit(&huart1, cmd, strlen((const char *)cmd), 1000);
//UART1_Receive(&handle, (uint8_t *)&rx_data, strlen(rx_data), 1000);

}
