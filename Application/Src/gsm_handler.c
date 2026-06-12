/*
 * gsm_handler.h
 *
 *  Created on: May 30, 2026
 *      Author: user
 */
#include <stdio.h>
#include <stdint.h>
#include "gsm_handler.h"
#include "gsm_com.h"
char adcbuffer[20];

void GSM_HANDLER(uint32_t adc_data){

	sprintf(adcbuffer, "Temp : %lu \r\n",adc_data);

	DataToPhone((uint8_t *)adcbuffer);


						/*
						 *  unsigned long int ADC_DATA = ADC_HANDLER();
						 * sprintf(adcbuffer, "temp : %lu\r\n",ADC_DATA);
						 * DataToPhone((uint8_t *)adcbuffer);
						 */


}
