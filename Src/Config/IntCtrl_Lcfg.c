/******************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------*/
/*      
 *  \file  		IntCtrl_Lcfg.c
 *  \brief 		NVIC Driver configuration file
 * 
 *  \details	The file containing configured data to be used by the NVIC driver
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
	IntrCtrl_GPIO_Port_F
};
uint8_t IntCtrl_nActvInr = sizeof(activeInterrupts)/sizeof(IntCtrl_InterruptType);
IntCtrl_InterruptPriority interruptPriorityVals[] = {
	/**	 	Fill in the interrupts priority values	  **/
	/* TODO:: Comment for usage */
	{IntrCtrl_GPIO_Port_F, 0x03}
};

IntCtrl_ExceptionPriority exceptionPriorityVals[] = {
	
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
 *  END OF FILE:    IntCtrl_Lcfg.c
 *****************************************************************************************************/
