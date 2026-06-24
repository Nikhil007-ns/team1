/*
 * Comm_LCD.h
 *
 *  Created on: May 15, 2026
 *      Author: ASUS
 */

#ifndef INC_COMM_LCD_H_
#define INC_COMM_LCD_H_

#include "stm32f4xx_hal.h"
#define i2c_handler  I2C_HandleTypeDef

void TCM_lcd_init(void);
void TCM_lcd_send_cmd(char cmd);
void TCM_lcd_send_data(char data);
void TCM_lcd_send_string(char *str);
void TCM_lcd_clear(void);

 void TCM_MX_GPIO_Init(void);
 void TCM_MX_I2C1_Init(void);
 void TCM_SystemClock_Config(void);

#endif /* INC_COMM_LCD_H_ */
