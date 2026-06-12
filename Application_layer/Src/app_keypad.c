/*
 * app_keypad.c
 *
 *  Created on: May 29, 2026
 *      Author: ksree
 */

#include "main.h"
#include "app_keypad.h"
#include "com_flash.h"
#include "com_gpio.h"
#include "uart.h"
#include "cmsis_os.h"

#include <string.h>
#include <stdlib.h>
#include "stdio.h"

#define FLASH_USER_START_ADDR    0x08060000UL
#define MAX_DIGITS               2
#define KEYPAD_DEBOUNCE_MS 20

//char kay_val;
char abhi;
//int chandan;
//void app_init(void)
//{
//    UART_Print("\r\n=============================\r\n");
//    UART_Print("  STM32 Keypad Flash Demo\r\n");
//    UART_Print("  Press B to erase Flash memory first\r\n");
//    UART_Print("  Then type 2 digits + press A\r\n");
//    UART_Print("=============================\r\n");
//}

const char KEYMAP[4][4] =
{
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

 const uint16_t ROW_PINS[4] =
{
		gpio_pin_1,gpio_pin_4,gpio_pin_5,gpio_pin_8

};

 const uint16_t COL_PINS[4] =
{
		gpio_pin_0,gpio_pin_1,gpio_pin_2,gpio_pin_4
};


void keypad_handler(void)
{
    static char number[MAX_DIGITS + 1];
    static uint8_t index = 0;
    static uint8_t flash_ready = 0;

    char key;


    key = keypad_scan();

    if(key == 0)
        return;

    if (key == 'A')
    {
        if (flash_ready && (index == MAX_DIGITS))
        {
            number[index] = '\0';

            uint32_t value = (uint32_t)atoi(number);
//            UART_Print("\r\npress A\r\n");

            Flash_Write(FLASH_USER_START_ADDR, value);

            UART_Print("\r\nFlash Write Done\r\n");

            flash_ready = 0;

            index = 0;

            memset(number,0,sizeof(number));
        }
//        else
//        {
//            UART_Print("\r\nInvalid Input\r\n");
//        }
    }
    else if (key == 'B')
    {
       UART_Print("Erasing Flash...\r\n");

        Flash_Erase();

        UART_Print("Flash Erase Done\r\n");

        flash_ready = 1;

        index = 0;

        memset(number,0,sizeof(number));
    }

    else if (key >= '0' && key <= '9')
    {
    	                  if(index < MAX_DIGITS)
    	                  {
    					  number[index++] = key;
    		              char echo[10];
    		              sprintf(echo, "%c", key);
    		              UART_Print(echo);
    		              if (index == MAX_DIGITS)
    		                  UART_Print("\r\n[INFO] 2 digits done. Press A to store.\r\n");
    	                  }
    	                  else
    	                  {
    	                 	              index = 0;
    	                 	              memset(number, 0, sizeof(number));
    	                 	              number[index++] = key;
    	                 	              //UART_Print("\r\n[INFO] Input reset: ");
    	                 	              char echo[10];
    	                 	              sprintf(echo, "%c", key);
    	                 	              UART_Print(echo);
    	                 	              /////these below two lines i am adding////////////
    	                 	             // if (index == MAX_DIGITS)
    	                 	            // UART_Print("\r\n[INFO] 2 digits done. Press A to store.\r\n");
                        }
    }
}

char keypad_scan(void)
{
	//chandan++;
    for(int row=0; row<4; row++)
    {
        GPIO_WritePin(gpioa, gpio_pin_1 | gpio_pin_4 |gpio_pin_5 | gpio_pin_8, gpio_pin_reset);

        GPIO_WritePin(gpioa,ROW_PINS[row],gpio_pin_set);

        osDelay(1);
        for(int col=0; col<4; col++)
        {
            if(GPIO_ReadPin(gpiob,COL_PINS[col]) == gpio_pin_set)
            {
            	osDelay(KEYPAD_DEBOUNCE_MS);
                if(GPIO_ReadPin(gpiob,COL_PINS[col]) == gpio_pin_set)
                {
                	while(GPIO_ReadPin(gpiob,COL_PINS[col]) == gpio_pin_set)
                	{
                	 abhi = KEYMAP[row][col];
                	}
                    //osDelay(KEYPAD_DEBOUNCE_MS);
                    return abhi;
                    //return abhi;
                }
            }
        }
    }

return 0;
}
