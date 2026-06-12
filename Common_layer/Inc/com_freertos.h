/*
 * com_freertos.h
 *
 *  Created on: Jun 4, 2026
 *      Author: ksree
 */

#ifndef INC_COM_FREERTOS_H_
#define INC_COM_FREERTOS_H_

#include "main.h"
#include "cmsis_os2.h"
typedef osThreadId_t      OSThreadID_t;


typedef osThreadFunc_t   OSThreadFunc_t;



typedef enum {
	OSPriorityNone          =  0,         ///< No priority (not initialized).
  OSPriorityIdle          =  1,         ///< Reserved for Idle thread.
  OSPriorityLow           =  8,         ///< Priority: low
  OSPriorityLow1          =  8+1,       ///< Priority: low + 1
  OSPriorityLow2          =  8+2,       ///< Priority: low + 2
  OSPriorityLow3          =  8+3,       ///< Priority: low + 3
  OSPriorityLow4          =  8+4,       ///< Priority: low + 4
  OSPriorityLow5          =  8+5,       ///< Priority: low + 5
  OSPriorityLow6          =  8+6,       ///< Priority: low + 6
  OSPriorityLow7          =  8+7,       ///< Priority: low + 7
  OSPriorityBelowNormal   = 16,         ///< Priority: below normal
  OSPriorityBelowNormal1  = 16+1,       ///< Priority: below normal + 1
  OSPriorityBelowNormal2  = 16+2,       ///< Priority: below normal + 2
  OSPriorityBelowNormal3  = 16+3,       ///< Priority: below normal + 3
  OSPriorityBelowNormal4  = 16+4,       ///< Priority: below normal + 4
  OSPriorityBelowNormal5  = 16+5,       ///< Priority: below normal + 5
  OSPriorityBelowNormal6  = 16+6,       ///< Priority: below normal + 6
  OSPriorityBelowNormal7  = 16+7,       ///< Priority: below normal + 7
  OSPriorityNormal        = 24,         ///< Priority: normal
  OSPriorityNormal1       = 24+1,       ///< Priority: normal + 1
  OSPriorityNormal2       = 24+2,       ///< Priority: normal + 2
  OSPriorityNormal3       = 24+3,       ///< Priority: normal + 3
  OSPriorityNormal4       = 24+4,       ///< Priority: normal + 4
  OSPriorityNormal5       = 24+5,       ///< Priority: normal + 5
  OSPriorityNormal6       = 24+6,       ///< Priority: normal + 6
  OSPriorityNormal7       = 24+7,       ///< Priority: normal + 7
  OSPriorityAboveNormal   = 32,         ///< Priority: above normal
  OSPriorityAboveNormal1  = 32+1,       ///< Priority: above normal + 1
  OSPriorityAboveNormal2  = 32+2,       ///< Priority: above normal + 2
  OSPriorityAboveNormal3  = 32+3,       ///< Priority: above normal + 3
  OSPriorityAboveNormal4  = 32+4,       ///< Priority: above normal + 4
  OSPriorityAboveNormal5  = 32+5,       ///< Priority: above normal + 5
  OSPriorityAboveNormal6  = 32+6,       ///< Priority: above normal + 6
  OSPriorityAboveNormal7  = 32+7,       ///< Priority: above normal + 7
  OSPriorityHigh          = 40,         ///< Priority: high
  OSPriorityHigh1         = 40+1,       ///< Priority: high + 1
  OSPriorityHigh2         = 40+2,       ///< Priority: high + 2
  OSPriorityHigh3         = 40+3,       ///< Priority: high + 3
  OSPriorityHigh4         = 40+4,       ///< Priority: high + 4
  OSPriorityHigh5         = 40+5,       ///< Priority: high + 5
  OSPriorityHigh6         = 40+6,       ///< Priority: high + 6
  OSPriorityHigh7         = 40+7,       ///< Priority: high + 7
  OSPriorityRealtime      = 48,         ///< Priority: realtime
  OSPriorityRealtime1     = 48+1,       ///< Priority: realtime + 1
  OSPriorityRealtime2     = 48+2,       ///< Priority: realtime + 2
  OSPriorityRealtime3     = 48+3,       ///< Priority: realtime + 3
  OSPriorityRealtime4     = 48+4,       ///< Priority: realtime + 4
  OSPriorityRealtime5     = 48+5,       ///< Priority: realtime + 5
  OSPriorityRealtime6     = 48+6,       ///< Priority: realtime + 6
  OSPriorityRealtime7     = 48+7,       ///< Priority: realtime + 7
  OSPriorityISR           = 56,         ///< Reserved for ISR deferred thread.
  OSPriorityError         = -1,         ///< System cannot determine priority or illegal priority.
  OSPriorityReserved      = 0x7FFFFFFF  ///< Prevents enum down-size compiler optimization.
} OSPriority_t;


typedef struct {
  const char                   *NAME;   ///< name of the memory pool
  uint32_t                 attr_bits;   ///< attribute bits
  void                      *cb_mem;    ///< memory for control block
  uint32_t                   cb_size;   ///< size of provided memory for control block
  void                      *mp_mem;    ///< memory for data storage
  uint32_t                   mp_size;   ///< size of provided memory for data storage
} OSMemoryPoolAttr_t;

typedef struct {
  const char                   *NAME;   ///< name of the thread
  uint32_t                 attr_bits;   ///< attribute bits
  void                      *cb_mem;    ///< memory for control block
  uint32_t                   cb_size;   ///< size of provided memory for control block
  void                   *stack_mem;    ///< memory for stack
  uint32_t                STACK_SIZE;   ///< size of stack
  osPriority_t              PRIORITY;   ///< initial thread priority (default: osPriorityNormal)
  TZ_ModuleId_t            tz_module;   ///< TrustZone module identifier
  uint32_t                  reserved;   ///< reserved (must be 0)
} OSThreadAttr_t;

void MX_FREERTOS_INIT(void);
 void StartDefaultTask(void *argument);
 void StartkeypadTask(void *argument);

 OSThreadID_t MY_OSThreadNew (osThreadFunc_t func, void *argument, const OSThreadAttr_t *attr);

#endif /* INC_COM_FREERTOS_H_ */
