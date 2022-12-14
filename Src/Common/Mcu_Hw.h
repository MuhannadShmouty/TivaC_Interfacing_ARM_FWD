/***************************************************************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------------------------------------------------*/
/*          File:       Mcu_Hw.h
 *        Module:       Mcu_Hw
 *   Description:       Header File for TM4C123GH6PM Registers Definition
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

typedef struct
{
	uint32_t EN			 :1;
	uint32_t INTEN   :1;
	uint32_t CLK_SRC :1;
	uint32_t         :13;
	uint32_t COUNT   :1;
	uint32_t 				 :15;
} STCTRL_BF;

typedef union
{
    uint32_t R;
    STCTRL_BF B;
}STCTRL_Tag;

typedef struct
{
	uint32_t RELOAD   :24;
	uint32_t 					:8;
} STRELOAD_BF;

typedef union
{
	uint32_t R;
	STRELOAD_BF B;
} STRELOAD_Tag;

typedef struct
{
	uint32_t CURRENT		:24;
	uint32_t						:8;
} STCURRENT_BF;

typedef union
{
	uint32_t R;
	STCURRENT_BF B;
} STCURRENT_Tag;
/***************************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 ***************************************************************************************************************************/
#define CORTEX_M4_PERIPH_BASE_ADDRESS       0xE000E000
#define APINT                               (*((volatile      uint32_t*)(CORTEX_M4_PERIPH_BASE_ADDRESS + 0xD0C)))
#define INTCTRL                             (*((volatile   INTCTRL_Tag*)(CORTEX_M4_PERIPH_BASE_ADDRESS + 0xD04)))
#define STCTRL															(*((volatile    STCTRL_Tag*)(CORTEX_M4_PERIPH_BASE_ADDRESS + 0x010)))
#define STRELOAD														(*((volatile  STRELOAD_Tag*)(CORTEX_M4_PERIPH_BASE_ADDRESS + 0x014)))
#define STCURRENT														(*((volatile STCURRENT_Tag*)(CORTEX_M4_PERIPH_BASE_ADDRESS + 0x018)))

#define GPIO_BASE_ADDRESS										0x40004000
#define PERIPH_BB_BASE_ADDRESS							0x42000000


#define GPIODEN_OFFSET											0x51C
#define GPIODIR_OFFSET											0x400
#define GPIODR2R_OFFSET											0x500
#define GPIODR4R_OFFSET											0x504
#define GPIODR8R_OFFSET											0x508
#define GPIO_ODR_OFFSET											0x50C
#define GPIO_PUR_OFFSET											0x510
#define GPIO_PDR_OFFSET											0x514

#define SYSTEM_CTRL_BASE_ADDRESS						0x400FE000
#define RCC																	(*((volatile     RCC_Tag*)(SYSTEM_CTRL_BASE_ADDRESS + 0x060)))
#define RCC2																(*((volatile    RCC2_Tag*)(SYSTEM_CTRL_BASE_ADDRESS + 0x070)))
#define PLLSTAT															(*((volatile  PLLSTAT_BF*)(SYSTEM_CTRL_BASE_ADDRESS + 0x168)))
#define RCGCGPIO														(*((volatile RCGCGPIO_BF*)(SYSTEM_CTRL_BASE_ADDRESS + 0x608)))

/***************************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **************************************************************************************************************************/


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
