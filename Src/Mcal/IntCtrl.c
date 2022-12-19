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
#define APINT_PRIGROUP_POS							8
#define THREE_BITS_MAX_VALUE						8
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
static bool isInterrutptType(uint8_t intNum);

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
	#else
		#error "Invalid Priority Group/Subgroup"
	#endif
}

static bool isInterrutptType(uint8_t intNum)
{
	bool isValid = true;
	switch(intNum)
	{
		case IntrCtrl_GPIO_Port_A:
		case IntrCtrl_GPIO_Port_B:
		case IntrCtrl_GPIO_Port_C:
		case IntrCtrl_GPIO_Port_D:
		case IntrCtrl_GPIO_Port_E:
		case IntrCtrl_UART0:
		case IntrCtrl_UART1:
		case IntrCtrl_SSI0:
		case IntrCtrl_I2C0:
		case IntrCtrl_PWM0_Fault:
		case IntrCtrl_PWM0_Generator_0:
		case IntrCtrl_PWM0_Generator_1:
		case IntrCtrl_PWM0_Generator_2:
		case IntrCtrl_QEI0:
		case IntrCtrl_ADC0_Sequence_0:
		case IntrCtrl_ADC0_Sequence_1:
		case IntrCtrl_ADC0_Sequence_2:
		case IntrCtrl_ADC0_Sequence_3:
		case IntrCtrl_Watchdog_Timers_0_and_1:
		case IntrCtrl_16_32_Timer_0A:
		case IntrCtrl_16_32_Timer_0B:
		case IntrCtrl_16_32_Timer_1A:
		case IntrCtrl_16_32_Timer_1B:
		case IntrCtrl_16_32_Timer_2A:
		case IntrCtrl_16_32_Timer_2B:
		case IntrCtrl_Analog_Comparator_0:
		case IntrCtrl_Analog_Comparator_1:
		case IntrCtrl_System_Control:
		case IntrCtrl_Flash_Memory_Control_and_EEPROM_Control:
		case IntrCtrl_GPIO_Port_F:
		case IntrCtrl_UART2:
		case IntrCtrl_SSI1:
		case IntrCtrl_Timer_3A:
		case IntrCtrl_Timer_3B:
		case IntrCtrl_I2C1:
		case IntrCtrl_QEI1:
		case IntrCtrl_CAN0:
		case IntrCtrl_CAN1:
		case IntrCtrl_Hibernation_Module:
		case IntrCtrl_USB:
		case IntrCtrl_PWM0_Generator_3:
		case IntrCtrl_uDMA_Software:
		case IntrCtrl_uDMA_Error:
		case IntrCtrl_ADC1_Sequence_0:
		case IntrCtrl_ADC1_Sequence_1:
		case IntrCtrl_ADC1_Sequence_2:
		case IntrCtrl_ADC1_Sequence_3:
		case IntrCtrl_SSI2:
		case IntrCtrl_SSI3:
		case IntrCtrl_UART3:
		case IntrCtrl_UART4:
		case IntrCtrl_UART5:
		case IntrCtrl_UART6:
		case IntrCtrl_UART7:
		case IntrCtrl_I2C2:
		case IntrCtrl_I2C3:
		case IntrCtrl_16_32_Timer_4A:
		case IntrCtrl_16_32_Timer_4B:
		case IntrCtrl_16_32_Timer_5A:
		case IntrCtrl_16_32_Timer_5B:
		case IntrCtrl_32_64_Timer_0A:
		case IntrCtrl_32_64_Timer_0B:
		case IntrCtrl_32_64_Timer_1A:
		case IntrCtrl_32_64_Timer_1B:
		case IntrCtrl_32_64_Timer_2A:
		case IntrCtrl_32_64_Timer_2B:
		case IntrCtrl_32_64_Timer_3A:
		case IntrCtrl_32_64_Timer_3B:
		case IntrCtrl_32_64_Timer_4A:
		case IntrCtrl_32_64_Timer_4B:
		case IntrCtrl_32_64_Timer_5A:
		case IntrCtrl_32_64_Timer_5B:
		case IntrCtrl_System_Exception:
		case IntrCtrl_PWM1_Generator_0:
		case IntrCtrl_PWM1_Generator_1:
		case IntrCtrl_PWM1_Generator_2:
		case IntrCtrl_PWM1_Generator_3:
		case IntrCtrl_PWM1_Fault:
			break;
		default:
			isValid = false;
	}
	return isValid;
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
	
	for (uint8_t idx = 0; idx < IntCtrl_nActvInr; idx++)
	{
		IntCtrl_EnableInterrupt(activeInterrupts[idx]);
		IntCtrl_SetPriority(interruptPriorityVals[idx].interruptNum, interruptPriorityVals[idx].priorityVal);
	}
}

/***********************************************************************************************************
 * \Syntax              : uint8_t IntCtrl_SetPriority(IntCtrl_InterruptType IntNum, uint32_t u32_IntPriority)
 * \Description         : Set the interrupt priority value of the given peripheral
 * 
 * \Sync\Async          : Synchronous
 * \Reentrancy          : Non Reentrant
 * \Parameters     (in) : (IntCtrl_InterruptType)Interrupt number corresponds to the peripheral in the vector table
 * \Parameters     (in) : (uint32_t)Interrupt priority value (0-7)
 * \Parameters     (out): None
 * \Return         value: (STD_TYPES_OK, STD_TYPES_NOK) Corresponds to the behaviour of the function
 **********************************************************************************************************/
uint8_t IntCtrl_SetPriority(IntCtrl_InterruptType IntNum, uint32_t u32_IntPriority)
{
	/**		Check for valid priority value  **/
	if ((u32_IntPriority < THREE_BITS_MAX_VALUE) && isInterrutptType(IntNum))
	{
		PRIx(IntNum) |= u32_IntPriority	<< (IntNum % 4);
		return STD_TYPES_OK;
	}
	return STD_TYPES_NOK;
}

/***********************************************************************************************************
 * \Syntax              : void IntCtrl_EnableInterrupt(IntCtrl_InterruptType IntNum)
 * \Description         : Enables the interrupt for the given peripheral
 * 
 * \Sync\Async          : Synchronous
 * \Reentrancy          : Non Reentrant
 * \Parameters     (in) : (IntCtrl_InterruptType)Interrupt number corresponds to the peripheral in the vector table
 * \Parameters     (out): None
 * \Return         value: None
 **********************************************************************************************************/
void IntCtrl_EnableInterrupt(IntCtrl_InterruptType IntNum)
{
	if (isInterrutptType(IntNum))
		ENx(IntNum) |= 1 << (IntNum % 32);
}

/***********************************************************************************************************
 * \Syntax              : void IntCtrl_DisableInterrupt(IntCtrl_InterruptType IntNum)
 * \Description         : Disables the interrupt for the given peripheral
 * 
 * \Sync\Async          : Synchronous
 * \Reentrancy          : Non Reentrant
 * \Parameters     (in) : (IntCtrl_InterruptType)Interrupt number corresponds to the peripheral in the vector table
 * \Parameters     (out): None
 * \Return         value: None
 **********************************************************************************************************/
void IntCtrl_DisableInterrupt(IntCtrl_InterruptType IntNum)
{
	if (isInterrutptType(IntNum))
		DISx(IntNum) |= 1 << (IntNum & 32);
}
/******************************************************************************************************
 *  END OF FILE:    IntCtrl.c
 *****************************************************************************************************/
