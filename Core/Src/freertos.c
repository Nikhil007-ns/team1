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
#include "FreeRTOSConfig.h"
#include "uart.h"
#include "app_keypad.h"
#include "cmsis_os2.h"
#include "com_freertos.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
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

OSThreadID_t defaultTaskHandle;
const OSThreadAttr_t defaultTask_attributes = {
  .NAME = "defaultTask",
  .STACK_SIZE = 128 * 4,
  .PRIORITY = (OSPriority_t) OSPriorityNormal,
};
/* Definitions for keypadtask */
OSThreadID_t keypadtaskHandle;
const OSThreadAttr_t keypadtask_attributes = {
  .NAME = "keypadtask",
  .STACK_SIZE = 256 * 4,
  .PRIORITY = (OSPriority_t) OSPriorityLow,
};

/* USER CODE END Variables */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

 void MX_FREERTOS_INIT(void)
  {
	  defaultTaskHandle = MY_OSThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

      keypadtaskHandle = MY_OSThreadNew(StartkeypadTask, NULL, &keypadtask_attributes);

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

/* USER CODE BEGIN Header_StartkeypadTask */
/**
* @brief Function implementing the keypadtask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartkeypadTask */

void StartkeypadTask(void *argument)
{
    //char msg[50];
   // uint32_t count = 0;

   // UBaseType_t stackLeft;

    for(;;)
    {
        keypad_handler();

//      count++;
//      if(count >= 5000)
//      {
//      count = 0;
//      stackLeft = uxTaskGetStackHighWaterMark(NULL);
//
//      sprintf(msg,"Free Stack: %lu\r\n", stackLeft);
//
//      UART_Print(msg);
      //}
      osDelay(1);
    }
}
/* USER CODE END Application */

