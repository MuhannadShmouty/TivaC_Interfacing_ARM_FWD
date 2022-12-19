/***************************************************************************************************************************
 *  FILE DESCRIPTION
 *  ----------------------------------------------------------------------------------------------------------------------*/
/*          File:       IntCtrl_Cfg.h
 *        Module:       IntCtrl
 *   Description:       The file containing configured data declerations to be used by the NVIC driver
 *
 **************************************************************************************************************************/

#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/***************************************************************************************************************************
 *  INCLUDES
 **************************************************************************************************************************/

/***************************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **************************************************************************************************************************/
/*
 *		Interrupt Control Priority Grouping
 *		Options:
 *			INTCTRL_GR_8_SB_1_PRIORITY_GROUP					:		bxxx.
 *			INTCTRL_GR_4_SB_2_PRIORITY_GROUP					:		bxx.y
 *			INTCTRL_GR_2_SB_4_PRIORITY_GROUP					:		bx.yy
 *			INTCTRL_GR_1_SB_8_PRIORITY_GROUP					:		b.yyy
*/
#define INTCTRL_GR_4_SB_2_PRIORITY_GROUP
/***************************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **************************************************************************************************************************/

/***************************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **************************************************************************************************************************/

/***************************************************************************************************************************
 *  GLOBAL DATA PROTOTYES
 **************************************************************************************************************************/

/***************************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **************************************************************************************************************************/


#endif

/***************************************************************************************************************************
 *  END OF FILE:    IntCtrl_Cfg.h
 **************************************************************************************************************************/
 
 