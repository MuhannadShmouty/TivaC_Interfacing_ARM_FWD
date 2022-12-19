/***************************************************************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------------------------------------------------*/
/*          File:       Mcu_Hw.h
 *        Module:       Mcu_Hw
 *   Description:       Header File for Registers Definition
 *
 **************************************************************************************************************************/

#ifndef MCU_HW_H
#define MCU_HW_H

/***************************************************************************************************************************
 *  INCLUDES
 **************************************************************************************************************************/
#include "Std_Types.h"

/***************************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **************************************************************************************************************************/

typedef struct
{
    uint32_t VECAT      :8;
    uint32_t            :3;      
    uint32_t RETBASE    :1;
    uint32_t VECPEND	  :7;
    uint32_t            :2;      
    uint32_t ISRPEND    :1;
    uint32_t ISRPRE     :1;
    uint32_t            :1;      
    uint32_t PENDSTCLR  :1;
    uint32_t PENDSTSET  :1;
    uint32_t UNPENDSV   :1;
    uint32_t PENDSV     :1;
    uint32_t            :2;      
    uint32_t NMISET     :1;
}INTCTRL_BF;

typedef union
{
    uint32_t R;
    INTCTRL_BF B;
}INTCTRL_Tag;


typedef struct
{
	uint32_t MOSCDIS		:1;
	uint32_t 						:3;
	uint32_t OSCSRC			:2;
	uint32_t XTAL				:5;
	uint32_t BYPASS			:1;
	uint32_t						:1;
	uint32_t PWRDN			:1;
	uint32_t						:3;
	uint32_t PWMDIV			:3;
	uint32_t USEPWMDIV	:1;
	uint32_t						:1;
	uint32_t USESYSDIV  :1;
	uint32_t SYSDIV			:4;
	uint32_t ACG				:1;
	uint32_t						:4;
} RCC_BF;

typedef union
{
    uint32_t R;
    RCC_BF B;
}RCC_Tag;

typedef struct
{
	uint32_t LOCK				:1;
	uint32_t						:31;
}PLLSTAT_BF;

typedef struct
{
	uint32_t        		:4;
	uint32_t OSCSRC2		:3;
	uint32_t      			:4;
	uint32_t BYPASS2		:1;
	uint32_t      			:1;
	uint32_t PWRDN2			:1;
	uint32_t USBPWRDN		:1;
	uint32_t						:7;
	uint32_t SYSDIV2LSB	:1;
	uint32_t SYSDIV2  	:6;
	uint32_t						:1;
	uint32_t DIV400			:1;
	uint32_t USERCC2		:1;
} RCC2_BF;

typedef union
{
    uint32_t R;
    RCC2_BF B;
}RCC2_Tag;

typedef struct
{
	uint32_t R0			:1;
	uint32_t R1			:1;
	uint32_t R2			:1;
	uint32_t R3			:1;
	uint32_t R4			:1;
	uint32_t R5			:1;
	uint32_t 				:27;
}RCGCGPIO_BF;



/***************************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 ***************************************************************************************************************************/
#define CORTEX_M4_PERIPH_BASE_ADDRESS       0xE000E000
#define APINT                               (*((volatile    uint32_t*)(CORTEX_M4_PERIPH_BASE_ADDRESS + 0xD0C)))
#define INTCTRL                             (*((volatile INTCTRL_Tag*)(CORTEX_M4_PERIPH_BASE_ADDRESS + 0xD04)))

#define GPIO_BASE_ADDRESS										0x40004000
#define PERIPH_BB_BASE_ADDRESS							0x42000000
#define GPIODEN_OFFSET											0x51C
#define GPIODIR_OFFSET											0x400

#define SYSTEM_CTRL_BASE_ADDRESS						0x400FE000
#define RCC																	(*((volatile    RCC_Tag*)(SYSTEM_CTRL_BASE_ADDRESS + 0x060)))
#define RCC2																(*((volatile   RCC2_Tag*)(SYSTEM_CTRL_BASE_ADDRESS + 0x070)))
#define PLLSTAT															(*((volatile PLLSTAT_BF*)(SYSTEM_CTRL_BASE_ADDRESS + 0x168)))
#define RCGCGPIO														(*((volatile RCGCGPIO_BF*)(SYSTEM_CTRL_BASE_ADDRESS + 0x608)))
/***************************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **************************************************************************************************************************/
#define GPIO_OFFSET(PORT_NUM)		 (PORT_NUM<4? ((GPIO_BASE_ADDRESS)+((PORT_NUM)*0x1000)):((0x40024000)+((PORT_NUM-4)*0x1000)))


#define GPIO_BB_OFFSET(PORT_NUM)				(PORT_NUM<4? ((0x00004000)+((PORT_NUM)*0x1000)):((0x00024000)+((PORT_NUM-4)*0x1000)))
#define GPIO_BB_SET_BIT(PORT_NUM, OFFSET, BIT_NO)				(*(volatile uint32_t *)((PERIPH_BB_BASE_ADDRESS)\
																										+ ((GPIO_BB_OFFSET(PORT_NUM)+OFFSET) * 32) + (BIT_NO * 4))) = 1
#define GPIO_BB_CLR_BIT(PORT_NUM, OFFSET, BIT_NO)				(*(volatile uint32_t *)((PERIPH_BB_BASE_ADDRESS)\
																										+ ((GPIO_BB_OFFSET(PORT_NUM) + OFFSET) * 32) + (BIT_NO * 4))) = 0

#define GPIO_MSK_SET_BIT(port, pin)									(*(volatile uint32_t*)(GPIO_OFFSET(port) + ((1<<pin)<<2))) = 1<<pin
#define GPIO_MSK_CLR_BIT(port, pin)									(*(volatile uint32_t*)(GPIO_OFFSET(port) + ((1<<pin)<<2))) = 0<<pin

/***************************************************************************************************************************
 *  GLOBAL DATA PROTOTYES
 **************************************************************************************************************************/

/***************************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **************************************************************************************************************************/


#endif

/***************************************************************************************************************************
 *  END OF FILE:    Mcu_Hw.h
 ***************************************************************************************************************************/
