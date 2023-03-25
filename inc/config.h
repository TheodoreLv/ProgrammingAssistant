/******************************************************************************
 * @file config.h
 * @version V1.0
 * @author Theodore Leo
 ******************************************************************************
 * @attention 
*******************************************************************************/
#ifndef __CONFIG_H
#define __CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

// <<< Use Configuration Wizard in Context Menu >>>

// <h> Basic Configuration

    // <h> Version
        // <i> �汾����
        // <o> Main Version
        // <i> ���汾��
        #define VERSION_MAIN 0
        // <o> Minor Version
        // <i> ��Ҫ����
        #define VERSION_MIONOR 1
        // <o> Revision Version
        // <i> �޶�����
        #define VERSION_REVISION 0
    // </h>
    
    // <e> Debug
        // <i> ��������
        #define USE_DEBUG 1
        // <c1> USE FULL ASSERT
        // <i> ʹ�ô������
        //#define USE_FULL_ASSERT
        // </c>
    // </e>
    
    // <e> Log
        // <i> ��־����
        #define USE_LOG 1
        // <o> Log Level
        // <i> ��־����ȼ�
        // <0U=> Critical
        // <1U=> Error
        // <2U=> Warning
        // <3U=> Info
        // <4U=> Debug
        #define LOG_LEVEL 4
        // <o> Log Output Port
        // <i> ��־����˿�
        // <0U=> SEGGER_RTT
        // <1U=> CMSIS_ITM
        // <2U=> USART
        #define LOG_OUTPUT_PORT 0
        // <c1> Use_Font_Folor
        // <i> ʹ�ò�ɫ���
        #define USE_FONT_COLOR
        // </c>
    // </e>
    
// </h>


// <h> Opration System Configuration
    // <o> Opration System Type
    // <i> ʹ��ʲô����ϵͳ
    // <0U=> None
    // <1U=> HAL
    // <2U=> TMOS
    // <3U=> RT-Thread
    // <4U=> FreeRTOS
    #define USED_OS_TYPE 3
// </h>

// <<< end of configuration section >>>

#ifdef __cplusplus
}
#endif

#endif
