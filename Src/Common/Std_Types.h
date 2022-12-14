/******************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------*/
/*          File:       Std_Types.h
 *        Module:       -
 *   Description:       <File Description here>
 *
 *****************************************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

/******************************************************************************************************
 *  INCLUDES
 *****************************************************************************************************/
#include <stdbool.h>
/******************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *****************************************************************************************************/
#define STD_TYPES_OK            1
#define STD_TYPES_NOK           0

#define NULL                   ((void*)0)
/******************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *****************************************************************************************************/

/******************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *****************************************************************************************************/
/* Signed integer types */
typedef   signed           char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;

/* Unsigned integer types */
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;



/******************************************************************************************************
 *  GLOBAL DATA PROTOTYES
 *****************************************************************************************************/

/******************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *****************************************************************************************************/


#endif

/******************************************************************************************************
 *  END OF FILE:    Std_Types.h
 *****************************************************************************************************/
 