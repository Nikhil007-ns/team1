/*
 * App_LCD.c
 *
 *  Created on: May 15, 2026
 *      Author: ASUS
 */
#include"App_LCD.h"
#include"Comm_LCD.h"
#define LCD_ADDR (0x27 << 1)
  i2c_handler hi2c1;

void LCD_Handler(void)
{
	 TCM_lcd_init();
	 TCM_lcd_send_cmd(0x80);
	 TCM_lcd_send_string("VRM");
	 TCM_lcd_send_cmd(0xC0);
	 TCM_lcd_send_data('1');
}
char data_u, data_l;
    uint8_t data_t[4];

void TCM_lcd_send_cmd(char cmd)
{
//    char data_u, data_l;
//    uint8_t data_t[4];

    data_u = cmd & 0xf0;
    data_l = (cmd << 4) & 0xf0;

    data_t[0] = data_u | 0x0C;
    data_t[1] = data_u | 0x08;
    data_t[2] = data_l | 0x0C;
    data_t[3] = data_l | 0x08;

    i2c_master_transmit(&hi2c1, LCD_ADDR, data_t, 4, 100);
}

void TCM_lcd_send_data(char data)
{
    char data_u, data_l;
    uint8_t data_t[4];

    data_u = data & 0xf0;
    data_l = (data << 4) & 0xf0;

    data_t[0] = data_u | 0x0D;
    data_t[1] = data_u | 0x09;
    data_t[2] = data_l | 0x0D;
    data_t[3] = data_l | 0x09;

    i2c_master_transmit(&hi2c1, LCD_ADDR, data_t, 4, 100);
}

void TCM_lcd_clear(void)
{
    TCM_lcd_send_cmd(0x01);
    HAL_Delay(2);
}

void TCM_lcd_init(void)
{
    HAL_Delay(50);

    TCM_lcd_send_cmd(0x30);
    HAL_Delay(5);

    TCM_lcd_send_cmd(0x30);
    HAL_Delay(1);

    TCM_lcd_send_cmd(0x30);
    HAL_Delay(10);

    TCM_lcd_send_cmd(0x20);
    HAL_Delay(10);

    TCM_lcd_send_cmd(0x28);
    HAL_Delay(1);

    TCM_lcd_send_cmd(0x08);
    HAL_Delay(1);

    TCM_lcd_clear();

    TCM_lcd_send_cmd(0x06);
    HAL_Delay(1);

    TCM_lcd_send_cmd(0x0C);
}


void TCM_lcd_send_string(char *str)
{
    while(*str)
    {
        TCM_lcd_send_data(*str++);
    }
}
