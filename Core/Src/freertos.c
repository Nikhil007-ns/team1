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
#include <rtos_com.h>
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "cmsis_os2.h"
#include "gsm_handler.h"
#include "gsm_com.h"
#include "uart_com.h"
#include"queue.h"
#include "rtos_com.h"
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

uint32_t stack_size;
uint8_t *msg_prio;
osStatus_t ID,ID1;
uint32_t count =1;
uint32_t space =1;
volatile uint32_t rx_data;
uint32_t temp;
uint8_t msgreceivebuff[100];
uint32_t Data =11;

ubasetype_t free_words;
osmessagequeueID_t  gsmqueue_ID;
osstatus_t           gsmreceivequeue_status;


osthreadID_t defaultTaskHandle;
osthreadID_t myTask02Handle;
osthreadID_t myTask03Handle;



//////////////////////////////////////////////////////////////////

/* Definitions for defaultTask */
 const osthreadattr_t defaultTask_attributes = {
  .Name = "defaultTask",
  .Stack_Size = 128 * 4,
  .Priority = (ospriority_t) osprioritynone,
};


/* Definitions for myTask02 */
 const osthreadattr_t myGSMTask_attributes = {
  .Name = "myTask02",
  .Stack_Size = 512 * 4,
  .Priority = (ospriority_t)  osprioritynormal,
};


/*definitions for mytask03*/
const osthreadattr_t myTask03_attributes = {
  .Name = "myTask03",
  .Stack_Size = 512 * 4,
  .Priority = (ospriority_t)  osprioritynormal1,
};

////////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////////

/*queue attributes details*/
osmessagequeueattr_t gsmattribute = {
		.Name = "gsm_queue"

};

/////////////////////////////////////////////////////////////////

/*Message queue list*/
		Queue_config_t Queue_list[] =
					{
						{QUEUE_COUNT,MESSAGE_SIZE, &gsmattribute}


					};


/*TASK LIST*/
		Task_Config_t Task_list[] =
					{

						{StartDefaultTask , 0 ,&defaultTask_attributes},
						{GSM_TASK, (uint32_t *)TIME_RECEIVE_QUEUE , &myGSMTask_attributes }

					};





/* USER CODE END Variables */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */


/* USER CODE END FunctionPrototypes */

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */


void Createqueue(void)
{

	for(int i = 0 ; i < sizeof(Queue_list)/sizeof(Queue_list[0])  ;i++)
	{

	  my_osMessageQueueNew (Queue_list[i].msg_count, Queue_list[i].msg_size, Queue_list[i].attributes);

	}

}



void MY_RTOS_Threads(void){

		for(int i = 0; i<sizeof(Task_list)/sizeof(Task_list[0]); i++)
		{

			my_osThreadNew(Task_list[i].func_task,(uint32_t *)Task_list[i].argument,Task_list[i].attributes);

		}
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


void GSM_TASK(void *TIMERECEIVEQUEUE)
{
  /* USER CODE BEGIN StartTask02 */
  /* Infinite loop */

				GSM_CONFIG();

  for(;;)
  {

	  	  //adc_value = ADC_HANDLER(); or do receive queue here
	  	   if(my_osMessageQueueGet (gsmqueue_ID, &temp, NULL,  *(uint32_t *)TIMERECEIVEQUEUE) == osok)
	  	   {
	  	   /*continously receive data store in circular buffer and send or receive every 1 min and end 2 options */

	  		GSM_HANDLER(temp);
	  	   }

  }
  /* USER CODE END StartTask02 */
}
/* USER CODE END Application */



void ADC_TASK(void *Argument)
{
	count = my_osMessageQueueGetCount(gsmqueue_ID);
//	space = osMessageQueueGetSpace(gsmqueue_ID);
		for(;;){

				//

		//	Data = ADC_HANDLER();
				ID  =	my_osMessageQueuePut(gsmqueue_ID,&Data,1, TIME_TRANSMIT_QUEUE);

				osDelay(1000);
		}
}

//void Createqueue(void)
//{
//
//	 osmessagequeueattr_t  gsmattribute = {
//                 .Name = "gsm_queue",
//
//	 };
//
//	//gsmqueue = xQueueCreate(QUEUE_LENGTH ,ITEM_SIZE);
//
//	 gsmqueue_ID = my_osMessageQueueNew (QUEUE_COUNT, MESSAGE_SIZE, &gsmattribute);
//
//	if(gsmqueue_ID == NULL)
//	{
//
//		//queue not created
//	}
//
//}


//void MY_Rtos_thread_create(void){
//
///*creation default task*/
//
////defaultTaskHandle = osThreadNew (StartDefaultTask,NULL,  &defaultTask_attributes );
//	my_osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);
//
//
//
///* creation of myTask02 */
//myTask02Handle = my_osThreadNew(GSM_TASK , (uint32_t *)TIME_RECEIVE_QUEUE , &myTask02_attributes);
////osThreadNew(myTask02Handle, NULL, &defaultTask_attributes);
//
//
//myTask03Handle = my_osThreadNew(ADC_TASK ,NULL , &myTask03_attributes);
//
//
//
//
////free_words = uxTaskGetStackHighWaterMark(myTask02Handle);
////stack_size = osThreadGetStackSize (myTask02Handle);
////stack_size= osThreadGetStackSize(myTask02Handle);
//
//
//
//}
