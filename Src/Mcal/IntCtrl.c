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
#include "IntCtrl.h"

/******************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTIONS
 *****************************************************************************************************/
#define VECT_KEY_MSK								0x05FA
#define VECT_KEY_POS								16
#define APINT_PRIGROUP_POS					8
#define THREE_BITS_MAX_VALUE				8
/******************************************************************************************************
 *  LOCAL DATA
 *****************************************************************************************************/
#define PRIx(i)        (*(volatile uint32_t*)(CORTEX_M4_PERIPH_BASE_ADDRESS + ((0x0400 + ((i/4)*4)))) )
#define ENx(i)         (*(volatile uint32_t*)(CORTEX_M4_PERIPH_BASE_ADDRESS + ((0x0100 + ((i/32)*32)))))
#define DISx(i)        (*(volatile uint32_t*)(CORTEX_M4_PERIPH_BASE_ADDRESS + ((0x0180 + ((i/32)*32)))))
#define PENDx(i)       (*(volatile uint32_t*)(CORTEX_M4_PERIPH_BASE_ADDRESS + ((0x0200 + ((i/32)*32)))))
#define UNPENDx(i)     (*(volatile uint32_t*)(CORTEX_M4_PERIPH_BASE_ADDRESS + ((0x0280 + ((i/32)*32)))))
#define ACTIVEx(i)     (*(volatile uint32_t*)(CORTEX_M4_PERIPH_BASE_ADDRESS + ((0x0300 + ((i/32)*32)))))
/******************************************************************************************************
 *  GLOBAL DATA
 *****************************************************************************************************/
extern IntCtrl_ExceptionType activeExceptions[];
extern IntCtrl_InterruptType activeInterrupts[];
extern IntCtrl_InterruptPriority interruptPriorityVals[];
extern IntCtrl_ExceptionPriority exceptionPriorityVals[];

extern uint8_t IntCtrl_nActvExp;
extern uint8_t IntCtrl_nActvInr;
/******************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *****************************************************************************************************/
static void SetPriorityGrouping(void);

/******************************************************************************************************
 *  LOCAL FUNCTIONS
 *****************************************************************************************************/

static void SetPriorityGrouping(void)
{
	
	#ifdef INTCTRL_GR_8_SB_1_PRIORITY_GROUP
	APINT = (VECT_KEY_MSK << VECT_KEY_POS) | (0x00000000 << APINT_PRIGROUP_POS);
	
	#elif defined(INTCTRL_GR_4_SB_2_PRIORITY_GROUP)
	APINT = (VECT_KEY_MSK << VECT_KEY_POS) | (0x00000005 << APINT_PRIGROUP_POS);
	
	#elif defined(INTCTRL_GR_2_SB_4_PRIORITY_GROUP)
	APINT = (VECT_KEY_MSK << VECT_KEY_POS) | (0x00000006 << APINT_PRIGROUP_POS);
	
	#elif defined(INTCTRL_GR_1_SB_8_PRIORITY_GROUP)
	APINT = (VECT_KEY_MSK << VECT_KEY_POS) | (0x00000007 << APINT_PRIGROUP_POS);
	
	#endif
}


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
 * \Parameters     (in) : None
 * \Parameters     (out): None
 * \Return value        : None
 *******************************************************************************/
void  IntCtrl_Init(void)
{
	/* Set priority grouping in APINT	*/
	SetPriorityGrouping();
}

uint8_t IntCtrl_SetPriority(IntCtrl_InterruptType IntNum, uint32_t u32_IntPriority)
{
	/**		Check for valid priority value  **/
	if (u32_IntPriority < THREE_BITS_MAX_VALUE)
	{
		PRIx(IntNum) = u32_IntPriority	<< (IntNum % 4);
		return STD_TYPES_OK;
	}
	return STD_TYPES_NOK;
}


void IntCtrl_EnableInterrupt(IntCtrl_InterruptType IntNum)
{
	ENx(IntNum) |= 1 << (IntNum & 32);
}

void IntCtrl_DisableInterrupt(IntCtrl_InterruptType IntNum)
{
	DISx(IntNum) |= 1 << (IntNum & 32);
}
/******************************************************************************************************
 *  END OF FILE:    IntCtrl.c
 *****************************************************************************************************/
