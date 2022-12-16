/******************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------*/
/*          File:       IntCtrl_Types.h
 *        Module:       -
 *   Description:       <File Description here>
 *
 *****************************************************************************************************/

#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/******************************************************************************************************
 *  INCLUDES
 *****************************************************************************************************/
#include "Std_Types.h"
/******************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *****************************************************************************************************/

/******************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *****************************************************************************************************/

/******************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *****************************************************************************************************/
typedef enum
{
    /* Containing Exceptions	*/
    MemoryManagment_IRQ,
    BusFault_IRQ,
    UsageFault_IRQ,
    SVCall_IRQ,
    DebugMonitor_IRQ,
    PendSV_IRQ,
    SysTick_IRQ
}IntCtrl_ExceptionType;

typedef enum
{
	/* Containing Interrupts	*/
	IntrCtrl_GPIO_Port_A, IntrCtrl_GPIO_Port_B, IntrCtrl_GPIO_Port_C, IntrCtrl_GPIO_Port_D, IntrCtrl_GPIO_Port_E,
	IntrCtrl_UART0, IntrCtrl_UART1,
	IntrCtrl_SSI0,
	IntrCtrl_I2C0,
	IntrCtrl_PWM0_Fault,	IntrCtrl_PWM0_Generator_0,	IntrCtrl_PWM0_Generator_1,	IntrCtrl_PWM0_Generator_2,
	IntrCtrl_QEI0,
	IntrCtrl_ADC0_Sequence_0, IntrCtrl_ADC0_Sequence_1,	IntrCtrl_ADC0_Sequence_2, IntrCtrl_ADC0_Sequence_3,
	IntrCtrl_Watchdog_Timers_0_and_1,
	IntrCtrl_16_32_Timer_0A,	IntrCtrl_16_32_Timer_0B,
	IntrCtrl_16_32_Timer_1A,	IntrCtrl_16_32_Timer_1B,
	IntrCtrl_16_32_Timer_2A,	IntrCtrl_16_32_Timer_2B,
	IntrCtrl_Analog_Comparator_0, IntrCtrl_Analog_Comparator_1,
	IntrCtrl_System_Control = 28,
	IntrCtrl_Flash_Memory_Control_and_EEPROM_Control,
	IntrCtrl_GPIO_Port_F,
	IntrCtrl_UART2 = 33,
	IntrCtrl_SSI1,
	IntrCtrl_Timer_3A, IntrCtrl_Timer_3B,
	IntrCtrl_I2C1,
	IntrCtrl_QEI1,
	IntrCtrl_CAN0, IntrCtrl_CAN1,
	IntrCtrl_Hibernation_Module = 43,
	IntrCtrl_USB,
	IntrCtrl_PWM0_Generator_3,
	IntrCtrl_uDMA_Software,
	IntrCtrl_uDMA_Error,
	IntrCtrl_ADC1_Sequence_0, IntrCtrl_ADC1_Sequence_1,	IntrCtrl_ADC1_Sequence_2, IntrCtrl_ADC1_Sequence_3,
	IntrCtrl_SSI2 = 57, IntrCtrl_SSI3,
	IntrCtrl_UART3, IntrCtrl_UART4, IntrCtrl_UART5, IntrCtrl_UART6, IntrCtrl_UART7,
	IntrCtrl_I2C2 = 68, IntrCtrl_I2C3,
	IntrCtrl_16_32_Timer_4A, IntrCtrl_16_32_Timer_4B,
	IntrCtrl_16_32_Timer_5A = 92, IntrCtrl_16_32_Timer_5B,
	IntrCtrl_32_64_Timer_0A, IntrCtrl_32_64_Timer_0B,
	IntrCtrl_32_64_Timer_1A, IntrCtrl_32_64_Timer_1B,
	IntrCtrl_32_64_Timer_2A, IntrCtrl_32_64_Timer_2B,
	IntrCtrl_32_64_Timer_3A, IntrCtrl_32_64_Timer_3B,
	IntrCtrl_32_64_Timer_4A, IntrCtrl_32_64_Timer_4B,
	IntrCtrl_32_64_Timer_5A, IntrCtrl_32_64_Timer_5B,
	IntrCtrl_System_Exception,
	IntrCtrl_PWM1_Generator_0,	IntrCtrl_PWM1_Generator_1,	IntrCtrl_PWM1_Generator_2,
	IntrCtrl_PWM1_Generator_3, IntrCtrl_PWM1_Fault
}IntCtrl_InterruptType;

typedef struct {
	IntCtrl_InterruptType interruptNum;
	uint32_t priorityVal;
} IntCtrl_InterruptPriority;

typedef struct {
	IntCtrl_ExceptionType exceptionNum;
	uint32_t priorityVal;
} IntCtrl_ExceptionPriority;

/******************************************************************************************************
 *  GLOBAL DATA PROTOTYES
 *****************************************************************************************************/

/******************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *****************************************************************************************************/


#endif
/******************************************************************************************************
 *  END OF FILE:    IntCtrl_Types.h
 *****************************************************************************************************/