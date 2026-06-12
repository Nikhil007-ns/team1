/*
 * com_keypad.c
 *
 *  Created on: May 29, 2026
 *      Author: ksree
 */

#include "main.h"
#include "com_flash.h"

void Flash_Write(uint32_t address, uint32_t data)
{
    HAL_StatusTypeDef status;

    HAL_FLASH_Unlock();

    status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,address,data);

    HAL_FLASH_Lock();

    if(status != HAL_OK)
    {
        //UART_Print("Flash Write Failed\r\n");
 	     //   TCM_lcd_send_cmd(0x80);
 //   	        TCM_lcd_send_string("Flash Wr Error! ");
//    	        TCM_lcd_send_cmd(0xC0);
//    	        TCM_lcd_send_string("                ");
    }
}

uint32_t Flash_read(uint32_t address)
{
    return *(volatile uint32_t *)address;

}

void Flash_Erase(void)
{
    HAL_FLASH_Unlock();

    FLASH_EraseInitTypeDef EraseInitStruct;

    uint32_t SectorError = 0;

    EraseInitStruct.TypeErase = FLASH_TYPEERASE_SECTORS;

    EraseInitStruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;

    EraseInitStruct.Sector = FLASH_SECTOR_7;

    EraseInitStruct.NbSectors = 1;

    HAL_FLASHEx_Erase(&EraseInitStruct,&SectorError);

    HAL_FLASH_Lock();
}
