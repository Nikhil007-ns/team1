/*
 * gsm_com.h
 *
 *  Created on: May 30, 2026
 *      Author: user
 */

#ifndef INC_GSM_COM_H_
#define INC_GSM_COM_H_


#include "uart_com.h"

void GSM_CONFIG(void);
void DataToPhone(unsigned char *data);
void Gsm_Send_Cmd(unsigned char *cmd);
#endif /* INC_GSM_COM_H_ */
