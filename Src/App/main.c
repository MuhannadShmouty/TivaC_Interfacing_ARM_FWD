/******************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------*/
/*      
 *  \file  main.c
 *  \brief 
 * 
 *  \details
 *****************************************************************************************************/

/******************************************************************************************************
 *  INCLUDES
 *****************************************************************************************************/
#include "IntCtrl.h"
#include "SysCtrl.h"
#include "GPIO.h"
#include "Systick.h"


/******************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTIONS
 *****************************************************************************************************/

/******************************************************************************************************
 *  LOCAL DATA
 *****************************************************************************************************/
volatile bool state = true;
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
void Systick_HandlerRoutine(void);
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
int main(void)
{
	SysCtrl_Init();
	IntCtrl_Init();
	
	
	GPIO_Init(GPIO_PORT_F, GPIO_D1, AMP_DRIVE_8MA); 
	GPIO_Init(GPIO_PORT_F, GPIO_D2, AMP_DRIVE_8MA);
	GPIO_Init(GPIO_PORT_F, GPIO_D3, AMP_DRIVE_8MA);
	
	GPIO_setDirection(GPIO_PORT_F, GPIO_D0, INPUT_PULLUP); 
	GPIO_setDirection(GPIO_PORT_F, GPIO_D1, OUTPUT);
	GPIO_setDirection(GPIO_PORT_F, GPIO_D2, OUTPUT);
	GPIO_setDirection(GPIO_PORT_F, GPIO_D3, OUTPUT);
	GPIO_setDirection(GPIO_PORT_F, GPIO_D4, INPUT_PULLUP);
	
	Systick_Init(1000);
	
	Systick_cb(Systick_HandlerRoutine);
	
	
	while(1)
	{
		if (state)
		{
			GPIO_Write(GPIO_PORT_F, GPIO_D1, HIGH);
			GPIO_Write(GPIO_PORT_F, GPIO_D2, HIGH);
			GPIO_Write(GPIO_PORT_F, GPIO_D3, HIGH);
			
		}
		else
		{
			GPIO_Write(GPIO_PORT_F, GPIO_D1, LOW);
			GPIO_Write(GPIO_PORT_F, GPIO_D2, LOW);
			GPIO_Write(GPIO_PORT_F, GPIO_D3, LOW);
		}
	}
}


void Systick_HandlerRoutine(void)
{
	state = !state;
}
/******************************************************************************************************
 *  END OF FILE:    main.c
 *****************************************************************************************************/
