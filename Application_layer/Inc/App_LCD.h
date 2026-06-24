/*
 * App_LCD.h
 *
 *  Created on: May 15, 2026
 *      Author: ASUS
 */

#ifndef INC_APP_LCD_H_
#define INC_APP_LCD_H_

void LCD_Handler(void);
void TCM_lcd_init(void);
void TCM_lcd_send_cmd(char cmd);
void TCM_lcd_send_data(char data);
void TCM_lcd_send_string(char *str);
void TCM_lcd_clear(void);
#endif /* INC_APP_LCD_H_ */
