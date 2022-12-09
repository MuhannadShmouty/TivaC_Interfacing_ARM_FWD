/******************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------*/
/**      
 *  \file       IntCtrl.c
 *  \brief      Nested Vector Interrupt Control Driver
 * 
 *  \details    The driver configure all MCU interrupts priority into groups and subgroups
 *              Enable NVIC Interrupt Gate for peripherals
 *****************************************************************************************************/

/******************************************************************************************************
 *  INCLUDES
 *****************************************************************************************************/
#include "../Common/Std_Types.h"
#include "../Common/Mcu_Hw.h"

/******************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTIONS
 *****************************************************************************************************/

/******************************************************************************************************
 *  LOCAL DATA
 *****************************************************************************************************/

/******************************************************************************************************
 *  GLOBAL DATA
 *****************************************************************************************************/

/******************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *****************************************************************************************************/

/******************************************************************************************************
 *  LOCAL FUNCTIONS
 *****************************************************************************************************/

/******************************************************************************************************
 *  GLOBAL FUNCTIONS
 *****************************************************************************************************/

/********************************************************************************
 * \Syntax              : void IntCtrl_Init(void)
 * \Description         : Initialize NVIC\SCB Module by parsing the configuration
 *                        into NVIC\SCB registers
 * 
 * \Sync\Async          : Synchronous
 * \Reentrancy          : Non Reentrant
 * \Parameters     (in) : Nne
 * \Parameters     (out): None
 * \Return value        : None
 *******************************************************************************/
void  IntCtrl_Init(void)
{
    /* TODO :: Configure grouping\ subgrouping system in APINT registed in SCB */
    
    /* TODO :: Assign Group\Subgroup priority in NVIC_PRIx and SCB_SYSPRIx Registers */

    /* TODO :: Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
}


/******************************************************************************************************
 *  END OF FILE:    FileName.c
 *****************************************************************************************************/