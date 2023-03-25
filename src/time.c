/******************************************************************************
 * @file time.c
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
#include "stdint.h"
#include "config.h"
    
/** Types **/

/** Defines **/
    
/** Variables **/
static volatile uint32_t sys_tick;

/** Function Prototypes **/
void TickIncrease(void);

/** Functions **/
void TickIncrease(void)
{
    __disable_irq();
    sys_tick++;
    __enable_irq();
}

#if defined(USED_OS_TYPE) && (USED_OS_TYPE == 0)  ///< 不使用使用系统
uint32_t GetTick(void)
{
    return sys_tick;
}

void mdelay(uint32_t millisecond)
{
    static uint32_t end_millisecond;
    end_millisecond = GetTick() + millisecond;
    
    while (end_millisecond >= GetTick()) { }
}

/*******************************************************************************
* Function Name  : SysTick_Handler
* Description    : This function handles SysTick Handler.
* Input          : None
* Return         : None
*******************************************************************************/
void SysTick_Handler(void)
{
    TickIncrease();
}

#endif

#ifdef __cplusplus
}
#endif
