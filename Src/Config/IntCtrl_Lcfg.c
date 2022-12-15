/******************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------*/
/*      
 *  \file  IntCtrl_Lcfg.c
 *  \brief 
 * 
 *  \details
 *****************************************************************************************************/

/******************************************************************************************************
 *  INCLUDES
 *****************************************************************************************************/
#include "IntCtrl_Types.h"

/******************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTIONS
 *****************************************************************************************************/

/******************************************************************************************************
 *  LOCAL DATA
 *****************************************************************************************************/

/******************************************************************************************************
 *  GLOBAL DATA
 *****************************************************************************************************/
IntCtrl_ExceptionType activeExceptions[] = {
	/**	 	Fill in the exceptions to be active	  **/
	/* TODO:: Comment for usage */
	
};
uint8_t IntCtrl_nActvExp = sizeof(activeExceptions)/sizeof(IntCtrl_ExceptionType);

IntCtrl_InterruptType activeInterrupts[] = {
	/**	 	Fill in the interrupts to be active	  **/
	/* TODO:: Comment for usage */
	IntrCtrl_GPIO_Port_A
};
uint8_t IntCtrl_nActvInr = sizeof(activeInterrupts)/sizeof(IntCtrl_InterruptType);
IntCtrl_InterruptPriority interruptPriorityVals[] = {
	/**	 	Fill in the interrupts priority values	  **/
	/* TODO:: Comment for usage */
	{IntrCtrl_GPIO_Port_A, 0x04}
};

IntCtrl_ExceptionPriority exceptionPriorityVals[] = {
	{SVCall_IRQ, 0x00},
	{SysTick_IRQ,0x02}
};
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
 * \Syntax              : Std ReturnType FunctionName (AnyType parameterName)
 * \Description         : Describe this service
 * 
 * \Sync\Async          : Synchronous
 * \Reentrancy          : Non Reentrant
 * \Parameters     (in) : parameterName     Parameter Description
 * \Parameters     (out): None
 * \Return value        : Std_ReturnType    E_OK
 *                                          E_NOT_OK 
 *******************************************************************************/


/******************************************************************************************************
 *  END OF FILE:    main.c
 *****************************************************************************************************/