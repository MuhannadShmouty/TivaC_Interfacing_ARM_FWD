/***************************************************************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------------------------------------------------*/
/*          File:       Systick.h
 *        Module:       -
 *   Description:       <File Description here>
 *
 **************************************************************************************************************************/

#ifndef SYSTICK_H
#define SYSTICK_H

/***************************************************************************************************************************
 *  INCLUDES
 **************************************************************************************************************************/
#include "Mcu_Hw.h"
#include "Std_Types.h"
#include "Systick_Cfg.h"
/***************************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **************************************************************************************************************************/

/***************************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **************************************************************************************************************************/

/***************************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **************************************************************************************************************************/

/***************************************************************************************************************************
 *  GLOBAL DATA PROTOTYES
 **************************************************************************************************************************/
typedef void(*cb_type)(void);
/***************************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **************************************************************************************************************************/
void Systick_Init(uint32_t delay_ms);
void Systick_cb(cb_type ptr);
void SysTick_Handler(void);

#endif
/***************************************************************************************************************************
 *  END OF FILE:    Systick.h
 **************************************************************************************************************************/