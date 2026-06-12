/*
 * com_flash.h
 *
 *  Created on: May 29, 2026
 *      Author: ksree
 */

#ifndef INC_COM_FLASH_H_
#define INC_COM_FLASH_H_

#include "main.h"
uint32_t Flash_read(uint32_t address);
void Flash_Write(uint32_t address, uint32_t data);
void Flash_Erase(void);

#endif /* INC_COM_FLASH_H_ */
