/******************************************************************************
 * @file time.h
 * @version V1.0
 * @author Theodore Leo
 * @brief 
 ******************************************************************************
 * @attention 
*******************************************************************************/

#ifndef __TIME_H
#define __TIME_H

#ifdef __cplusplus
extern "C" {
#endif

/** Includes **/
#include "stdint.h"
#include "config.h"

/** Types **/

/** Defines **/

/** Variables **/

/** Functions Prototypes **/
#if defined(USED_OS_TYPE) && (USED_OS_TYPE == 0)  ///< ��ʹ��ʹ��ϵͳ
    uint32_t GetTick(void);
    void mdelay(uint32_t millisecond);
#elif defined(USED_OS_TYPE) && (USED_OS_TYPE == 1)  ///< ʹ��HAL
    #define mdelay(milliseconds)                    HAL_Delay(milliseconds)
    #define GetTick()                               HAL_GetTick()
#elif defined(USED_OS_TYPE) && (USED_OS_TYPE == 3)  ///< ʹ��RT-Threadʵʱϵͳ
    #include "rtthread.h"
    #define mdelay(milliseconds)                    rt_thread_mdelay(milliseconds)
    #define GetTick()                               rt_tick_get()
#endif

void TickIncrease(void);


#ifdef __cplusplus
}
#endif

#endif
