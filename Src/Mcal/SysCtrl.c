/******************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------*/
/*      
 *  \file  SysCtrl.c
 *  \brief 
 * 
 *  \details
 *****************************************************************************************************/

/******************************************************************************************************
 *  INCLUDES
 *****************************************************************************************************/
#include "SysCtrl.h"

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
static void SysCtrl_ChooseClk(void)
{
	/**  Configure Oscillator Choice  **/
	#ifdef MAIN_OSC
	/* Choose Main Oscillator as clock source */
	RCC.B.OSCSRC  = 0x00;
	/* Enable Main Oscillator */
	RCC.B.MOSCDIS = 0x00;
	#elif defined(PRECISION_INTERNAL_OSC)
	/* Choose Precision internal oscillator as clock source */
	RCC.B.OSCSRC  = 0x01;
	#elif defined(PRECISION_INTERNAL_OSC_DIV_4)
	/* Choose Precision internal oscillator / 4 as clock source */
	RCC.B.OSCSRC  = 0x02;
	#elif defined(LOW_FREQ_INTERNAL_OSC)
	/* Choose Low-frequency internal oscillator as clock source */
	RCC.B.OSCSRC  = 0x03;
	#else
		#error "Invalid Clock Source"
	#endif
}

static void SysCtrl_ClkSet(void)
{
	
	#ifdef SYSDIV_1
	RCC.B.SYSDIV = 0x00;
	#elif defined(SYSDIV_2)
	RCC.B.SYSDIV = 0x01;
	#elif defined(SYSDIV_3)
	RCC.B.SYSDIV = 0x02;
	#elif defined(SYSDIV_4)
	RCC.B.SYSDIV = 0x03;
	#elif defined(SYSDIV_5)
	RCC.B.SYSDIV = 0x04;
	#elif defined(SYSDIV_6)
	RCC.B.SYSDIV = 0x05;
	#elif defined(SYSDIV_7)
	RCC.B.SYSDIV = 0x06;
	#elif defined(SYSDIV_8)
	RCC.B.SYSDIV = 0x07;
	#elif defined(SYSDIV_9)
	RCC.B.SYSDIV = 0x08
	#elif defined(SYSDIV_10)
	RCC.B.SYSDIV = 0x09;
	#elif defined(SYSDIV_11)
	RCC.B.SYSDIV = 0xA;
	#elif defined(SYSDIV_12)
	RCC.B.SYSDIV = 0xB;
	#elif defined(SYSDIV_13)
	RCC.B.SYSDIV = 0xC;
	#elif defined(SYSDIV_14)
	RCC.B.SYSDIV = 0xD;
	#elif defined(SYSDIV_15)
	RCC.B.SYSDIV = 0xE;
	#elif defined(SYSDIV_16)
	RCC.B.SYSDIV = 0xF;
	#else
		#error "Invalid System Clock Divisor"
	#endif
	
}

static void SysCtrl_CfgPLL_Div(void)
{
	
}

static void SysCtrl_ActivatePeriphClk(void)
{
	#ifdef SYSCTRL_ACTVCLK_GPIOA
	RCGCGPIO.R0 = 1;
	#endif
	
	#ifdef SYSCTRL_ACTVCLK_GPIOB
	RCGCGPIO.R1 = 1;
	#endif
	
	#ifdef SYSCTRL_ACTVCLK_GPIOC
	RCGCGPIO.R2 = 1;
	#endif
	
	#ifdef SYSCTRL_ACTVCLK_GPIOD
	RCGCGPIO.R3 = 1;
	#endif
	
	#ifdef SYSCTRL_ACTVCLK_GPIOE
	RCGCGPIO.R4 = 1;
	#endif
	
	#ifdef SYSCTRL_ACTVCLK_GPIOF
	RCGCGPIO.R5 = 1;
	#endif
}
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
void SysCtrl_Init(void)
{
	/** Choose Clock source **/
	SysCtrl_ChooseClk();
	
	#ifdef PLL_USED
	/* Enable the PLL */
	RCC.B.PWRDN = 0x00;
	/* Wait until PLL is locked */
	while(PLLSTAT.LOCK == 0);
	/* Configure PLL divisor */
	SysCtrl_CfgPLL_Div();
	
	#elif defined(PLL_NOT_USED)
	/* The system clock is derived from the OSC source */
	RCC.B.BYPASS = 0x01;
	/* Power down the PLL */
	RCC.B.PWRDN = 0x01;
	#else
		#error "Invalid PLL State"
	#endif
	
	SysCtrl_ClkSet();
	
	/* Set the system clock divider as the source for the system clock */
	RCC.B.USESYSDIV = 1;
	
	/* Enable clock for the chosen peripherals */
	SysCtrl_ActivatePeriphClk();
}


/******************************************************************************************************
 *  END OF FILE:    SysClk.c
 *****************************************************************************************************/