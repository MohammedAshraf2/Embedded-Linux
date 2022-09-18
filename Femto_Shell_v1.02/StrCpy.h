/**
*******************************************
* @file             : StrCpy.h
* @author           : MohammedElsayaad
* @brief            : This file is header file containe every declration needed for the project, functions and macros
* 		       also it has user defined data type enum to make the code easier in reading.
*@Date              : 9 / 9 / 2022
*******************************************
*/


#ifndef _STRCPY_H

/********************* File Guard Defination Section Start ************************/

#define _STRCPY_H

/********************* File Guard Defination Section End ************************/


/********************* Linking Section Start ************************/

#include "Std_Library.h"
#include <string.h>

/********************* Linking Section End ************************/



/********************* Macros Section Start ************************/

#define EmptyPointer NULL
#define Matched       0
#define NotMatched    1
#define ArraySize     1024
#define TempArraySize 5

/********************* Macros Section End ************************/



/********************* User Defined Data Type Section Start ************************/

typedef enum
{
    N_OK =0,
    OK,
    NullPointer,
    Continue,
    N_Continue

}Status_t;

typedef enum
{
    Femto_Exit =0,
    Femto_Copy,
    Femto_Rand,
    Femto_Fact,
    Femto_Fib,
}option_t;

/********************* User Defined Data Type Section End ************************/



/********************* Function Declaration Section Start ************************/

option_t StrComp(const signed char ReceviedStr[],const unsigned int Length);
Status_t StrCpy_t(const signed char ReceviedStr[],const unsigned int Length,signed char *const OutStr);

/********************* Function Declaration Section End ************************/




#endif //_STRCPY_H
