/******************************************************************************
 * @file log.c
 * @version V1.0
 * @author Theodore Leo
 * @brief 
 ******************************************************************************
 * @attention 
*******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/** Includes **/
#include "stdio.h"
#include "config.h"
#if (LOG_OUTPUT_PORT == 0U)  // SEGGER_RTT
#include "SEGGER_RTT.h"
#elif (LOG_OUTPUT_PORT == 1U)  // CMSIS_ITM
#elif (LOG_OUTPUT_PORT == 2U)  // ����
#endif

/** Types **/

/** Defines **/

/** Variables **/

/** Function Prototypes **/

/** User Code **/

/** Private user code **/
int fputc(int ch, FILE * f)
{
    #if (LOG_OUTPUT_PORT == 0U)  // SEGGER_RTT ���
    SEGGER_RTT_PutChar(0, ch);
    #elif (LOG_OUTPUT_PORT == 1U)  // CMSIS_ITM ���
    ITM_SendChar(ch);
    #elif (LOG_OUTPUT_PORT == 2U)  // �������
    ///< @todo �����������
    #endif
    return ch;
}

#ifdef __cplusplus
}
#endif
