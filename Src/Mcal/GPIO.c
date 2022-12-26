/***********************************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------------------*/
/*      
 *  \file  FileName.c
 *  \brief 
 * 
 *  \details
 ***********************************************************************************************************************************/

/************************************************************************************************************************************
 *  INCLUDES
 ***********************************************************************************************************************************/
#include "GPIO.h"

/************************************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTIONS
 ***********************************************************************************************************************************/
#define GPIO_OFFSET(PORT_NUM)		 (PORT_NUM<4? ((GPIO_BASE_ADDRESS)+((PORT_NUM)*0x1000)):((0x40024000)+((PORT_NUM-4)*0x1000)))


#define GPIO_BB_OFFSET(PORT_NUM)				(PORT_NUM<4? ((0x00004000)+((PORT_NUM)*0x1000)):((0x00024000)+((PORT_NUM-4)*0x1000)))
#define GPIO_BB_SET_BIT(PORT_NUM, OFFSET, BIT_NO)				(*(volatile uint32_t *)((PERIPH_BB_BASE_ADDRESS)\
																	  + ((GPIO_BB_OFFSET(PORT_NUM)+OFFSET) * 32) + (BIT_NO * 4))) = 1
#define GPIO_BB_CLR_BIT(PORT_NUM, OFFSET, BIT_NO)				(*(volatile uint32_t *)((PERIPH_BB_BASE_ADDRESS)\
																	+ ((GPIO_BB_OFFSET(PORT_NUM) + OFFSET) * 32) + (BIT_NO * 4))) = 0

#define GPIO_MSK_SET_BIT(port, pin)								(*(volatile uint32_t*)(GPIO_OFFSET(port) + ((1<<pin)<<2))) = 1<<pin
#define GPIO_MSK_CLR_BIT(port, pin)								(*(volatile uint32_t*)(GPIO_OFFSET(port) + ((1<<pin)<<2))) = 0<<pin
#define GPIO_GET_BIT(port, pin)										((*(volatile uint32_t*)(GPIO_OFFSET(port) + ((1<<pin)<<2))) >> pin & 1)
/************************************************************************************************************************************
 *  LOCAL DATA
 ***********************************************************************************************************************************/

/************************************************************************************************************************************
 *  GLOBAL DATA
 ***********************************************************************************************************************************/

/************************************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 ***********************************************************************************************************************************/

/***********************************************************************************************************************************
 *  LOCAL FUNCTIONS
 ***********************************************************************************************************************************/

/************************************************************************************************************************************
 *  GLOBAL FUNCTIONS
 ***********************************************************************************************************************************/

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
void GPIO_Write(GPIO_PORT port, GPIO_PIN pin, GPIO_LEVEL state)
{	
	/* GPIO Set data */
	switch (state)
	{
		case HIGH:
			GPIO_MSK_SET_BIT(port, pin);
		break;
		case LOW:
			GPIO_MSK_CLR_BIT(port, pin);
		break;
	}
}

void GPIO_setDirection(GPIO_PORT port, GPIO_PIN pin, GPIO_DIR direction)
{
	/* GIPO Digital enable */
	GPIO_BB_SET_BIT(port, GPIODEN_OFFSET, pin);
	
	switch (direction)
	{
		case INPUT:
			/* GPIO Set direction */
			GPIO_BB_CLR_BIT(port, GPIODIR_OFFSET, pin);
		break;
		case OUTPUT:
			/* GPIO Set direction */
			GPIO_BB_SET_BIT(port, GPIODIR_OFFSET, pin);
		break;
		case OUTPUT_OPEN_DRAIN:
			GPIO_BB_SET_BIT(port, GPIO_ODR_OFFSET, pin);
			break;
		case INPUT_PULLUP:
			GPIO_BB_SET_BIT(port, GPIO_PUR_OFFSET, pin);
			break;
		case INPUT_PULLDOWN:
			GPIO_BB_SET_BIT(port, GPIO_PDR_OFFSET, pin);
			break;
	}
}

void GPIO_Init(GPIO_PORT port, GPIO_PIN pin, GPIO_AMP amps)
{
	switch (amps)
	{
		case AMP_DRIVE_2MA:
			GPIO_BB_SET_BIT(port, GPIODR2R_OFFSET, pin);
			break;
		case AMP_DRIVE_4MA:
			GPIO_BB_SET_BIT(port, GPIODR4R_OFFSET, pin);
			break;
		case AMP_DRIVE_8MA:
			GPIO_BB_SET_BIT(port, GPIODR8R_OFFSET, pin);
			break;
	}
}

uint32_t GPIO_Read(GPIO_PORT port, GPIO_PIN pin)
{
	
	return GPIO_GET_BIT(port, pin);
}
/***********************************************************************************************************************************
 *  END OF FILE:    FileName.c
 ***********************************************************************************************************************************/