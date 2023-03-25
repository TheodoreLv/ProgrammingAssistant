/******************************************************************************
 * @file debug.c
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
#include "stdio.h"
#include "config.h"

/** Types **/

/** Defines **/

/** Variables **/

/** Function Prototypes **/

/** User Code **/

/** Private user code **/


#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
**/
__weak void assert_failed(uint8_t *file, uint32_t line)
{
    /* USER CODE BEGIN 6 */
    printf("[Assert Failed] At %s : line %d", file, line);
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

#ifdef __cplusplus
}
#endif
