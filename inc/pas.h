/******************************************************************************
 * @file pas.h
 * @version V1.0
 * @author Theodore Leo
 * @brief 
 ******************************************************************************
 * @attention 
*******************************************************************************/
#ifndef __PAS_H
#define __PAS_H

#ifdef __cplusplus
extern "C" {
#endif

/** Includes **/
#include "stm32f4xx_hal.h"
#include "stdio.h"
#include "config.h"
#include "debug.h"
#include "log.h"
#include "time.h"

#if defined(USED_OS_TYPE) && (USED_OS_TYPE == 0)  ///< 无系统
#elif defined(USED_OS_TYPE) && (USED_OS_TYPE == 3)  ///< 使用RT-Thread实时系统
#include "rtthread.h"
#endif

/** Types **/

/** Defines **/


#define ShowSoftwareInfo() \
    printf("\r\n"); \
    printf("******************************\r\n"); \
    printf("*   Programming Aid System   *\r\n"); \
    printf("*          V%01d.%02d.%02d          *\r\n", VERSION_MAIN, VERSION_MIONOR, VERSION_REVISION); \
    printf("*     Build %s      *\r\n", __DATE__); \
    printf("******************************\r\n"); \
    printf("\r\n");

/** Variables **/

/** Functions Prototypes **/

#ifdef __cplusplus
}
#endif

#endif
