/******************************************************************************
 * @file queue.c
 * @version V1.0
 * @author Theodore Leo
 * @brief 
 ******************************************************************************
 * @attention 
 *      先读写数据后移动指针
 *      read_p == write_p时为空
 *      (write_p + 1) % len) == read_p时为满
*******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/** Includes **/
#include "stdint.h"
#include "queue.h"

/** Types **/

/** Defines **/

/** Variables **/

/** Function Prototypes **/

/** Functions **/
void InitQueueStruct(queue_pt q, uint8_t *buffer, uint32_t length)
{
    q->buffer = buffer;
    q->len = length;
    q->read_p = 0;
    q->write_p = 0;
}

uint32_t IsQueueEmpty(queue_pt q)
{
    if (q->read_p == q->write_p)
    {
        return 1;
    }
    return 0;
}

uint32_t IsQueueFull(queue_pt q)
{
    if (((q->write_p + 1) % q->len) == q->read_p)
    {
        return 1;
    }
    return 0;
}

QueueState_t QueueDelete(queue_pt q, uint32_t length)
{
    while (length > 0)
    {
        if (q->read_p == q->write_p)
        {
            return Queue_OK;
        }
        q->read_p = (q->read_p + 1) % q->len;
        length--;
    }
    return Queue_OK;
}

uint32_t QueueGetLength(queue_pt q)
{
    return (q->write_p + q->len - q->read_p) % q->len;
}

uint8_t QueueGetByte(queue_pt q, uint32_t index)
{
    return q->buffer[(q->read_p + index) % q->len];
}

QueueState_t QueueReadByte(queue_pt q, uint8_t *data, uint32_t index)
{
    if (q->read_p != q->write_p)
    {
        *data = q->buffer[(q->read_p + index) % q->len];
        return Queue_OK;
    }
    else
    {
        return Queue_EMPTY;
    }
}

QueueState_t QueueRead(queue_pt q, uint8_t *dst, uint32_t length)
{
    uint32_t index = 0;
    while (length > 0)
    {
        if (QueueReadByte(q, dst + index, index) == Queue_OK)
        {
            index++;
            length--;
        }
        else
        {
            return Queue_ERROR;
        }
    }
    return Queue_OK;
}

QueueState_t QueueWriteByte(queue_pt q, uint8_t data)
{
    if (((q->write_p + 1) % q->len) != q->read_p)
    {
        q->buffer[q->write_p] = data;
        q->write_p = (q->write_p + 1) % q->len;
        return Queue_OK;
    }
    else
    {
        return Queue_FULL;
    }
}

QueueState_t QueueWrite(queue_pt q, uint8_t *src, uint32_t length)
{
    while (length > 0)
    {
        if (QueueWriteByte(q, *(src)) == Queue_OK)
        {
            src++;
            length--;
        }
        else
        {
            return Queue_ERROR;
        }
    }
    return Queue_OK;
}

#ifdef __cplusplus
}
#endif
