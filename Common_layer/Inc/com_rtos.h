/*
 * com_rtos.h
 *
 *  Created on: Jun 4, 2026
 *      Author: ASUS
 */

#ifndef INC_COM_RTOS_H_
#define INC_COM_RTOS_H_
#include"cmsis_os2.h"
//#define OsThreadId_t osThreadId_t ;
//#define  OsThreadFunc_t osThreadFunc_t ;
//#define osThreadId_t  OsThreadId_t;

typedef osThreadId_t OsThreadId_t;
typedef osThreadFunc_t OsThreadFunc_t;
typedef struct {
  const char                   *Name;   ///< name of the thread
  uint32_t                 Attr_bits;   ///< attribute bits
  void                      *Cb_mem;    ///< memory for control block
  uint32_t                   Cb_size;   ///< size of provided memory for control block
  void                   *Stack_mem;    ///< memory for stack
  uint32_t                Stack_size;   ///< size of stack
  osPriority_t              Priority;   ///< initial thread priority (default: osPriorityNormal)
  TZ_ModuleId_t            Tz_module;   ///< TrustZone module identifier
  uint32_t                  Reserved;   ///< reserved (must be 0)
} OSThreadAttr_t;

typedef enum {
  OsPriorityNone          =  0,         ///< No priority (not initialized).
  OsPriorityIdle          =  1,         ///< Reserved for Idle thread.
  OsPriorityLow           =  8,         ///< Priority: low
  OsPriorityLow1          =  8+1,       ///< Priority: low + 1
  OsPriorityLow2          =  8+2,       ///< Priority: low + 2
  OsPriorityLow3          =  8+3,       ///< Priority: low + 3
  OsPriorityLow4          =  8+4,       ///< Priority: low + 4
  OsPriorityLow5          =  8+5,       ///< Priority: low + 5
  OsPriorityLow6          =  8+6,       ///< Priority: low + 6
  OsPriorityLow7          =  8+7,       ///< Priority: low + 7
  OsPriorityBelowNormal   = 16,         ///< Priority: below normal
  OsPriorityBelowNormal1  = 16+1,       ///< Priority: below normal + 1
  OsPriorityBelowNormal2  = 16+2,       ///< Priority: below normal + 2
  OsPriorityBelowNormal3  = 16+3,       ///< Priority: below normal + 3
  OsPriorityBelowNormal4  = 16+4,       ///< Priority: below normal + 4
  OsPriorityBelowNormal5  = 16+5,       ///< Priority: below normal + 5
  OsPriorityBelowNormal6  = 16+6,       ///< Priority: below normal + 6
  OsPriorityBelowNormal7  = 16+7,       ///< Priority: below normal + 7
  OsPriorityNormal        = 24,         ///< Priority: normal
  OsPriorityNormal1       = 24+1,       ///< Priority: normal + 1
  OsPriorityNormal2       = 24+2,       ///< Priority: normal + 2
  OsPriorityNormal3       = 24+3,       ///< Priority: normal + 3
  OsPriorityNormal4       = 24+4,       ///< Priority: normal + 4
  OsPriorityNormal5       = 24+5,       ///< Priority: normal + 5
  OsPriorityNormal6       = 24+6,       ///< Priority: normal + 6
  OsPriorityNormal7       = 24+7,       ///< Priority: normal + 7
  OsPriorityAboveNormal   = 32,         ///< Priority: above normal
  OsPriorityAboveNormal1  = 32+1,       ///< Priority: above normal + 1
  OsPriorityAboveNormal2  = 32+2,       ///< Priority: above normal + 2
  OsPriorityAboveNormal3  = 32+3,       ///< Priority: above normal + 3
  OsPriorityAboveNormal4  = 32+4,       ///< Priority: above normal + 4
  OsPriorityAboveNormal5  = 32+5,       ///< Priority: above normal + 5
  OsPriorityAboveNormal6  = 32+6,       ///< Priority: above normal + 6
  OsPriorityAboveNormal7  = 32+7,       ///< Priority: above normal + 7
  OsPriorityHigh          = 40,         ///< Priority: high
  OsPriorityHigh1         = 40+1,       ///< Priority: high + 1
  OsPriorityHigh2         = 40+2,       ///< Priority: high + 2
  OsPriorityHigh3         = 40+3,       ///< Priority: high + 3
  OsPriorityHigh4         = 40+4,       ///< Priority: high + 4
  OsPriorityHigh5         = 40+5,       ///< Priority: high + 5
  OsPriorityHigh6         = 40+6,       ///< Priority: high + 6
  OsPriorityHigh7         = 40+7,       ///< Priority: high + 7
  OsPriorityRealtime      = 48,         ///< Priority: realtime
  OsPriorityRealtime1     = 48+1,       ///< Priority: realtime + 1
  OsPriorityRealtime2     = 48+2,       ///< Priority: realtime + 2
  OsPriorityRealtime3     = 48+3,       ///< Priority: realtime + 3
  OsPriorityRealtime4     = 48+4,       ///< Priority: realtime + 4
  OsPriorityRealtime5     = 48+5,       ///< Priority: realtime + 5
  OsPriorityRealtime6     = 48+6,       ///< Priority: realtime + 6
  OsPriorityRealtime7     = 48+7,       ///< Priority: realtime + 7
  OsPriorityISR           = 56,         ///< Reserved for ISR deferred thread.
  OsPriorityError         = -1,         ///< System cannot determine priority or illegal priority.
  OsPriorityReserved      = 0x7FFFFFFF  ///< Prevents enum down-size compiler optimization.
} OsPriority_t;

osThreadId_t My_osThreadNew(OsThreadFunc_t func, void *argument, const OSThreadAttr_t *attr);
#endif /* INC_COM_RTOS_H_ */
