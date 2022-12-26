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
#include "SysCtrl.h"
#include "GPIO.h"
#include "Systick.h"


/******************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTIONS
 *****************************************************************************************************/

/******************************************************************************************************
 *  LOCAL DATA
 *****************************************************************************************************/
static volatile bool state = true;
static volatile uint32_t delay_ms = 0;
/* Each time value is represented in 1/4 seconds steps */
/* 16 = 4 * 4seconds */
static volatile uint32_t refTotalTime = 20, onTime = 16, offTime = 0, totalTime = 20;
/******************************************************************************************************
 *  GLOBAL DATA
 *****************************************************************************************************/

/******************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *****************************************************************************************************/

/******************************************************************************************************
 *  LOCAL FUNCTIONS
 *****************************************************************************************************/
static void PowerLEDs(uint32_t onTime, uint32_t offTime);
void Systick_HandlerRoutine(void);
/******************************************************************************************************
 *  GLOBAL FUNCTIONS
 *****************************************************************************************************/
int main(void)
{
	SysCtrl_Init();
	
	
	GPIO_Init(GPIO_PORT_F, GPIO_D1, AMP_DRIVE_8MA); 
	GPIO_Init(GPIO_PORT_F, GPIO_D2, AMP_DRIVE_8MA);
	GPIO_Init(GPIO_PORT_F, GPIO_D3, AMP_DRIVE_8MA);
	
	GPIO_setDirection(GPIO_PORT_F, GPIO_D0, INPUT_PULLUP); 
	GPIO_setDirection(GPIO_PORT_F, GPIO_D1, OUTPUT);
	GPIO_setDirection(GPIO_PORT_F, GPIO_D4, INPUT_PULLUP);
	
	
	delay_ms = 250;
	
	Systick_cb(Systick_HandlerRoutine);
	Systick_Init(delay_ms);
	
	while(1)
	{		
		if (state)
		{
			GPIO_Write(GPIO_PORT_F, GPIO_D1, HIGH);
		}
		else
		{
			GPIO_Write(GPIO_PORT_F, GPIO_D1, LOW);
		}
	}
}




void Systick_HandlerRoutine(void)
{
	
	/* Increment On time once every 1/4 second if SW1 is pressed */
	if (!GPIO_Read(GPIO_PORT_F, GPIO_D4))
	{
		onTime++;
		onTime = onTime > refTotalTime? refTotalTime : onTime;
		totalTime = refTotalTime;
	}
	/* Decrement On time once every 1/4 second if SW2 is pressed */
	else if (!GPIO_Read(GPIO_PORT_F, GPIO_D0))
	{
		onTime--;
		totalTime = refTotalTime;
	}
	PowerLEDs(onTime, offTime);
	
}

static void PowerLEDs(uint32_t onTime, uint32_t offTime)
{
	offTime = refTotalTime - onTime;
	if (totalTime > offTime + 1)
	{
		state = true;
		totalTime--;
	} else if (totalTime > 1)
	{
		state = false;
		totalTime--;
	} else
	{
		totalTime = refTotalTime;
	}
}

/******************************************************************************************************
 *  END OF FILE:    main.c
 *****************************************************************************************************/
