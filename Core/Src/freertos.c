/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os2.h"
#include "App_LCD.h"
#include "com_rtos.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
OsThreadId_t defaultTaskHandle;
OsThreadId_t lcd_handlerHandle;
/* USER CODE END Variables */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */


void LCDTask(void *argument);
void StartDefaultTask(void *argument);
/* USER CODE END FunctionPrototypes */

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
/* Definitions for lcd_handler */
void MX_FREERTOS_Init(void)
{

	const OSThreadAttr_t defaultTask_attributes = {
	  .Name = "defaultTask",
	  .Stack_size = 128 * 4,
	  .Priority = (OsPriority_t) OsPriorityNormal,
	};
    const OSThreadAttr_t lcdTask_attributes =
    {
        .Name = "lcdTask",
        .Stack_size = 512 * 4,
        .Priority = (OsPriority_t) OsPriorityNormal,
    };

    lcd_handlerHandle =My_osThreadNew(LCDTask, NULL, &lcdTask_attributes);
    defaultTaskHandle = My_osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);
}

void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */
}
void LCDTask(void *argument)
{
	for(;;)
    {
        LCD_Handler();

        osDelay(1000);
    }
}
/* USER CODE END Application */

