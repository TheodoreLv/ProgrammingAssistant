/******************************************************************************
 * @file queue.h
 * @version V1.0
 * @author Theodore Leo
 * @brief 
 ******************************************************************************
 * @attention 
*******************************************************************************/
#ifndef __QUEUE_H
#define __QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

/** Includes **/
#include "stdint.h"

/** Types **/
struct queue_t
{
    uint32_t write_p;
    uint32_t read_p;
    uint32_t len;
    uint8_t *buffer;
};
typedef struct queue_t *queue_pt;

typedef enum
{
    Queue_OK,
    Queue_ERROR,
    Queue_EMPTY,
    Queue_FULL
}QueueState_t;

/** Defines **/

/** Variables **/

/** Functions Prototypes **/
void InitQueueStruct(queue_pt q, uint8_t *buffer, uint32_t length);
uint32_t IsQueueEmpty(queue_pt q);
uint32_t IsQueueFull(queue_pt q);
uint32_t QueueGetLength(queue_pt q);
uint8_t QueueGetByte(queue_pt q, uint32_t index);
QueueState_t QueueDelete(queue_pt q, uint32_t length);
QueueState_t QueueReadByte(queue_pt q, uint8_t *data, uint32_t index);
QueueState_t QueueRead(queue_pt q, uint8_t *dst, uint32_t length);
QueueState_t QueueWriteByte(queue_pt q, uint8_t data);
QueueState_t QueueWrite(queue_pt q, uint8_t *src, uint32_t length);

#ifdef __cplusplus
}
#endif

#endif
