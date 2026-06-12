/*
 * rtos_com.c
 *
 *  Created on: Jun 4, 2026
 *      Author: user
 */
#include "rtos_com.h"
#include "main.h"
osthreadID_t my_osThreadNew ( osthreadfunc_t func, void *argument, const osthreadattr_t *attr)
{

		return osThreadNew(func, argument, attr);

}
osmessagequeueID_t my_osMessageQueueNew (uint32_t msg_count, uint32_t msg_size, const osmessagequeueattr_t *attr)
{

		osmessagequeueID_t messagequeueID;
		messagequeueID=	osMessageQueueNew(msg_count, msg_size, attr);
		return messagequeueID;

}
osstatus_t my_osMessageQueueGet (osmessagequeueId_t mq_id, void *msg_ptr, uint8_t *msg_prio, uint32_t timeout)
{

	return osMessageQueueGet(msg_ptr, msg_ptr, msg_prio, timeout);

}
osstatus_t my_osMessageQueuePut (osmessagequeueId_t mq_id, const void *msg_ptr, uint8_t msg_prio, uint32_t timeout)
{

	return osMessageQueuePut(mq_id, msg_ptr, msg_prio, timeout);

}

uint32_t my_osMessageQueueGetCount (osmessagequeueID_t mq_id)
{

	return osMessageQueueGetCount(mq_id);

}
