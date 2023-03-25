/******************************************************************************
 * @file log.h
 * @version V1.0
 * @author Theodore Leo
 * @brief 
 ******************************************************************************
 * @attention 
*******************************************************************************/
#ifndef __LOG_H
#define __LOG_H

#ifdef __cplusplus
extern "C" {
#endif

/** Exported Includes **/
#include "config.h"
#if (LOG_OUTPUT_PORT == 0U)
#include "SEGGER_RTT.h"
#endif
/** Exported Types **/

/** Exported Defines **/
#if (USE_LOG != 0U)
    #if (LOG_LEVEL <= 0)
    #define LOGD(format, ...)
    #define LOGI(format, ...)
    #define LOGW(format, ...)
    #define LOGE(format, ...)
    #define LOGC(format, ...)               LOG_Critical(format, ##__VA_ARGS__)
    #elif (LOG_LEVEL <= 1)
    #define LOGD(format, ...)
    #define LOGI(format, ...)
    #define LOGW(format, ...)
    #define LOGE(format, ...)               LOG_Error(format, ##__VA_ARGS__)
    #define LOGC(format, ...)               LOG_Critical(format, ##__VA_ARGS__)
    #elif (LOG_LEVEL <= 2)
    #define LOGD(format, ...)
    #define LOGI(format, ...)
    #define LOGW(format, ...)               LOG_Warning(format, ##__VA_ARGS__)
    #define LOGE(format, ...)               LOG_Error(format, ##__VA_ARGS__)
    #define LOGC(format, ...)               LOG_Critical(format, ##__VA_ARGS__)
    #elif (LOG_LEVEL <= 3)
    #define LOGD(format, ...)
    #define LOGI(format, ...)               LOG_Info(format, ##__VA_ARGS__)
    #define LOGW(format, ...)               LOG_Warning(format, ##__VA_ARGS__)
    #define LOGE(format, ...)               LOG_Error(format, ##__VA_ARGS__)
    #define LOGC(format, ...)               LOG_Critical(format, ##__VA_ARGS__)
    #elif (LOG_LEVEL <= 4)
    #define LOGD(format, ...)               LOG_Debug(format, ##__VA_ARGS__)
    #define LOGI(format, ...)               LOG_Info(format, ##__VA_ARGS__)
    #define LOGW(format, ...)               LOG_Warning(format, ##__VA_ARGS__)
    #define LOGE(format, ...)               LOG_Error(format, ##__VA_ARGS__)
    #define LOGC(format, ...)               LOG_Critical(format, ##__VA_ARGS__)
    #endif
    
    #if defined(USE_FONT_COLOR)
        #if (LOG_OUTPUT_PORT == 0U)  // SEGGER_RTT
            #define LOG_Debug(format, ...)          printf(RTT_CTRL_TEXT_WHITE"[Debug]" RTT_CTRL_RESET " " format "\r\n", ##__VA_ARGS__)
            #define LOG_Info(format, ...)           printf(RTT_CTRL_TEXT_GREEN"[Info]" RTT_CTRL_RESET " " format "\r\n", ##__VA_ARGS__)
            #define LOG_Warning(format, ...)        printf(RTT_CTRL_TEXT_YELLOW"[Warning]" RTT_CTRL_RESET " " format "\r\n", ##__VA_ARGS__)
            #define LOG_Error(format, ...)          printf(RTT_CTRL_TEXT_RED"[Error]" RTT_CTRL_RESET " " format "\r\n", ##__VA_ARGS__)
            #define LOG_Critical(format, ...)       printf(RTT_CTRL_BG_RED"[Critical]" RTT_CTRL_RESET " " format "\r\n", ##__VA_ARGS__)
        #elif (LOG_OUTPUT_PORT == 1U)  // CMSIS_ITM
        #elif (LOG_OUTPUT_PORT == 2U)  // ´®¿Ú
            #define LOG_STYLE_DEFAULT               "0"  // Ä¬ÈÏ
            #define LOG_STYLE_BOLD                  "1"  // ¸ßÁÁ
            #define LOG_STYLE_BLINK                 "5"  // ÉÁË¸
            #define LOG_STYLE_INV                   "7"  // ·µÏÔ

            #define LOG_COLOR_BLACK                 "30"
            #define LOG_COLOR_RED                   "31"
            #define LOG_COLOR_GREEN                 "32"
            #define LOG_COLOR_YELLOW                "33"
            #define LOG_COLOR_BLUE                  "34"
            #define LOG_COLOR_PURPLE                "35"
            #define LOG_COLOR_CYAN                  "36"
            #define LOG_COLOR_WHITE                 "37"

            #define LOG_COLOR(STYLE, COLOR)         "\033[" STYLE ";" COLOR "m"
            #define LOG_COLOR_RESET                 "\033[0m"

            #define LOG_COLOR_D                     LOG_COLOR(LOG_STYLE_DEFAULT, LOG_COLOR_WHITE)
            #define LOG_COLOR_I                     LOG_COLOR(LOG_STYLE_DEFAULT, LOG_COLOR_GREEN)
            #define LOG_COLOR_W                     LOG_COLOR(LOG_STYLE_DEFAULT, LOG_COLOR_YELLOW)
            #define LOG_COLOR_E                     LOG_COLOR(LOG_STYLE_DEFAULT, LOG_COLOR_RED)
            #define LOG_COLOR_C                     LOG_COLOR(LOG_STYLE_INV, LOG_COLOR_RED)

            #define LOG_Debug(format, ...)          printf(LOG_COLOR_D"[Debug]" LOG_COLOR_RESET " " format "\r\n", ##__VA_ARGS__)
            #define LOG_Info(format, ...)           printf(LOG_COLOR_I"[Info]" LOG_COLOR_RESET " " format "\r\n", ##__VA_ARGS__)
            #define LOG_Warning(format, ...)        printf(LOG_COLOR_W"[Warning]" LOG_COLOR_RESET " " format "\r\n", ##__VA_ARGS__)
            #define LOG_Error(format, ...)          printf(LOG_COLOR_E"[Error]" LOG_COLOR_RESET " " format "\r\n", ##__VA_ARGS__)
            #define LOG_Critical(format, ...)       printf(LOG_COLOR_C"[Critical]" LOG_COLOR_RESET " " format "\r\n", ##__VA_ARGS__)
        #endif
    #else
    #define LOG_Debug(format, ...)          printf("[Debug] " format "\r\n", ##__VA_ARGS__)
    #define LOG_Info(format, ...)           printf("[Info] " format "\r\n", ##__VA_ARGS__)
    #define LOG_Warning(format, ...)        printf("[Warning] " format "\r\n", ##__VA_ARGS__)
    #define LOG_Error(format, ...)          printf("[Error] " format "\r\n", ##__VA_ARGS__)
    #define LOG_Critical(format, ...)       printf("[Critical] " format "\r\n", ##__VA_ARGS__)
    #endif
#else
#define LOGD(format, ...)
#define LOGI(format, ...)
#define LOGW(format, ...)
#define LOGE(format, ...)
#define LOGC(format, ...)
#endif
/** Exported Functions Prototypes **/


#ifdef __cplusplus
}
#endif

#endif
