/*
 * rtos.h
 *
 *  Created on: Jun 1, 2026
 *      Author: user
 */

#ifndef INC_RTOS_COM_H_
#define INC_RTOS_COM_H_

#include "main.h"
#include "cmsis_os2.h"

#define QUEUE_COUNT              	10
#define MESSAGE_SIZE             	sizeof( uint32_t )
#define TIME_RECEIVE_QUEUE       	0
#define TIME_TRANSMIT_QUEUE      	10000
#define ubasetype_t              	UBaseType_t


typedef osMessageQueueId_t 			osmessagequeueID_t;
typedef osThreadId_t				osthreadID_t;
typedef TZ_ModuleId_t     	    	tz_moduleId_t;
typedef osThreadFunc_t          	osthreadfunc_t;
typedef osMessageQueueId_t      	osmessagequeueId_t;



/*priority information*/
typedef enum     //osPriority_t
	{
	      osprioritynone          =  0,         ///< No priority (not initialized).
		  ospriorityidle          =  1,         ///< Reserved for Idle thread.
		  osprioritylow           =  8,         ///< Priority: low
		  osprioritylow1          =  8+1,       ///< Priority: low + 1
		  osprioritylow2          =  8+2,       ///< Priority: low + 2
		  osprioritylow3          =  8+3,       ///< Priority: low + 3
		  osprioritylow4          =  8+4,       ///< Priority: low + 4
		  osprioritylow5          =  8+5,       ///< Priority: low + 5
		  osprioritylow6          =  8+6,       ///< Priority: low + 6
		  osprioritylow7          =  8+7,       ///< Priority: low + 7
		  osprioritybelowNormal   = 16,         ///< Priority: below normal
		  osprioritybelowNormal1  = 16+1,       ///< Priority: below normal + 1
		  osprioritybelowNormal2  = 16+2,       ///< Priority: below normal + 2
		  osprioritybelowNormal3  = 16+3,       ///< Priority: below normal + 3
		  osprioritybelowNormal4  = 16+4,       ///< Priority: below normal + 4
		  osprioritybelowNormal5  = 16+5,       ///< Priority: below normal + 5
		  osprioritybelowNormal6  = 16+6,       ///< Priority: below normal + 6
		  osprioritybelowNormal7  = 16+7,       ///< Priority: below normal + 7
		  osprioritynormal        = 24,         ///< Priority: normal
		  osprioritynormal1       = 24+1,       ///< Priority: normal + 1
		  osprioritynormal2       = 24+2,       ///< Priority: normal + 2
		  osprioritynormal3       = 24+3,       ///< Priority: normal + 3
		  osprioritynormal4       = 24+4,       ///< Priority: normal + 4
		  osprioritynormal5       = 24+5,       ///< Priority: normal + 5
		  osprioritynormal6       = 24+6,       ///< Priority: normal + 6
		  osprioritynormal7       = 24+7,       ///< Priority: normal + 7
		  ospriorityaboveNormal   = 32,         ///< Priority: above normal
		  ospriorityaboveNormal1  = 32+1,       ///< Priority: above normal + 1
		  ospriorityaboveNormal2  = 32+2,       ///< Priority: above normal + 2
		  ospriorityaboveNormal3  = 32+3,       ///< Priority: above normal + 3
		  ospriorityaboveNormal4  = 32+4,       ///< Priority: above normal + 4
		  ospriorityaboveNormal5  = 32+5,       ///< Priority: above normal + 5
		  ospriorityaboveNormal6  = 32+6,       ///< Priority: above normal + 6
		  ospriorityaboveNormal7  = 32+7,       ///< Priority: above normal + 7
		  ospriorityhigh          = 40,         ///< Priority: high
		  ospriorityhigh1         = 40+1,       ///< Priority: high + 1
		  ospriorityhigh2         = 40+2,       ///< Priority: high + 2
		  ospriorityhigh3         = 40+3,       ///< Priority: high + 3
		  ospriorityhigh4         = 40+4,       ///< Priority: high + 4
		  ospriorityhigh5         = 40+5,       ///< Priority: high + 5
		  ospriorityhigh6         = 40+6,       ///< Priority: high + 6
		  ospriorityhigh7         = 40+7,       ///< Priority: high + 7
		  ospriorityrealtime      = 48,         ///< Priority: realtime
		  ospriorityrealtime1     = 48+1,       ///< Priority: realtime + 1
		  ospriorityrealtime2     = 48+2,       ///< Priority: realtime + 2
		  ospriorityrealtime3     = 48+3,       ///< Priority: realtime + 3
		  ospriorityrealtime4     = 48+4,       ///< Priority: realtime + 4
		  ospriorityrealtime5     = 48+5,       ///< Priority: realtime + 5
		  ospriorityrealtime6     = 48+6,       ///< Priority: realtime + 6
		  ospriorityrealtime7     = 48+7,       ///< Priority: realtime + 7
		  ospriorityisr           = 56,         ///< Reserved for ISR deferred thread.
		  ospriorityerror         = -1,         ///< System cannot determine priority or illegal priority.
		  ospriorityreserved      = 0x7FFFFFFF  ///< Prevents enum down-size compiler optimization.
		}	ospriority_t;





typedef enum   //osStatus_t
		{
	  osok                      =  0,         ///< Operation completed successfully.
	  oserror                   = -1,         ///< Unspecified RTOS error: run-time error but no other error message fits.
	  oserrortimeout            = -2,         ///< Operation not completed within the timeout period.
	  oserrorresource           = -3,         ///< Resource not available.
	  oserrorparameter          = -4,         ///< Parameter error.
	  oserrornomemory           = -5,         ///< System is out of memory: it was impossible to allocate or reserve memory for the operation.
	  oserrorisr                = -6,         ///< Not allowed in ISR context: the function cannot be called from interrupt service routines.
	  osstatusreserved          = 0x7FFFFFFF  ///< Prevents enum down-size compiler optimization.

		}osstatus_t;

/*Thread creating attribute information*/
typedef struct //osThreadAttr_t
		{
	  	  const char                   *Name;   ///< name of the thread
	  	  uint32_t                 Attr_Bits;   ///< attribute bits
	  	  void                      *Cb_Mem;    ///< memory for control block
	  	  uint32_t                   Cb_Size;   ///< size of provided memory for control block
	  	  void                   *Stack_Mem;    ///< memory for stack
	  	  uint32_t                Stack_Size;   ///< size of stack
	   	  ospriority_t              Priority;   ///< initial thread priority (default: osPriorityNormal)
	   	  tz_moduleId_t            Tz_Module;   ///< TrustZone module identifier
	  	  uint32_t                  Reserved;   ///< reserved (must be 0)

		}osthreadattr_t;

/*For creating message queue information*/
typedef struct// osMessageQueueAttr_t
       {
	  	  const char                   *Name;   ///< name of the message queue
	  	  uint32_t                 Attr_Bits;   ///< attribute bits
	  	  void                      *Cb_Mem;    ///< memory for control block
	  	  uint32_t                   Cb_Size;   ///< size of provided memory for control block
	  	  void                      *Mq_Mem;    ///< memory for data storage
	  	  uint32_t                   Mq_Size;
		}osmessagequeueattr_t;



/*Task list config details*/
typedef	struct
		{
		osthreadfunc_t func_task;
		void * argument;
		const osthreadattr_t *attributes;

		}Task_Config_t;


/*Message queue config details*/
typedef struct
{
	uint32_t msg_count;
	uint32_t msg_size;
	const osmessagequeueattr_t *attributes;
}Queue_config_t;




//typedef struct{
//
//const char *name;
//uint32_t stack_size;
//osthreadfunc_t task_func;
//ospriority_t priotity;
//}Task_Config_t;







		void Createqueue(void);
		void StartDefaultTask(void *);
		void GSM_TASK(void *);
		void ADC_TASK(void *);
		void MY_RTOS_Threads(void);
		osthreadID_t my_osThreadNew (osthreadfunc_t , void *, const osthreadattr_t *);
		osmessagequeueID_t my_osMessageQueueNew (uint32_t msg_count, uint32_t msg_size, const osmessagequeueattr_t *attr);
		osstatus_t my_osMessageQueueGet (osmessagequeueId_t mq_id, void *msg_ptr, uint8_t *msg_prio, uint32_t timeout);
		osstatus_t my_osMessageQueuePut (osmessagequeueId_t mq_id, const void *msg_ptr, uint8_t msg_prio, uint32_t timeout);
		uint32_t my_osMessageQueueGetCount (osmessagequeueID_t mq_id);
		//ubasetype_t my_uxTaskGetStackHighWaterMark( TaskHandle_t xTask ) PRIVILEGED_FUNCTION;






#endif /* INC_RTOS_COM_H_ */

