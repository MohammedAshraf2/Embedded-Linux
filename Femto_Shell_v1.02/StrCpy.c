/**
*******************************************
* @file             : StrCpy.c
* @author           : MohammedElsayaad
* @brief            : This file contain the functions needed to run the FemtoShell application.
*@Date              : 9 / 9 / 2022
*******************************************
*/


/********************* Linking Section Start ************************/

#include "StrCpy.h"

/********************* Linking Section End ************************/


/********************* Defination Section Start ************************/

static signed char ExitArray[5]         = {'e','x','i','t'}; // hold string of program exit
static signed char RandArray[5]         = {'r','a','n','d'}; // hold string for rand func call
static signed char FactorialArray[5]    = {'f','a','c','t'}; // hold string for factorial func call
static signed char FibArray[4]         = {'f','i','b'};     // hold string for fibonacci series call

/********************* Defination Section End ************************/


/********************* Static Function Declration Section Start ************************/


static Status_t Usre_Option(const signed char UserArray[], const signed char TempArray[] ); 


/********************* Static Function Declration Section End ************************/


option_t StrComp(const signed char ReceviedStr[],const unsigned int Length)
{
    option_t RetVal = Femto_Exit;
    unsigned char Iterator =0,ExitValidation = Matched;
    
    if((0 == Length) || (ReceviedStr[0] == '\0'))
    {
        RetVal = Femto_Exit;
    }
    else
    {
	if(Usre_Option(ReceviedStr,ExitArray))
	{
	    RetVal = Femto_Exit;
	}
	else if(Usre_Option(ReceviedStr,RandArray))
	{
	    RetVal = Femto_Rand;
	}
	else if(Usre_Option(ReceviedStr,FactorialArray))
	{
	    RetVal = Femto_Fact;
	}
	else if(Usre_Option(ReceviedStr,FibArray))
	{
	    RetVal = Femto_Fib;
	}
	else
	{
	    RetVal = Femto_Copy;
	}
    }

    return (RetVal);
}



Status_t StrCpy_t(const signed char ReceviedStr[],const unsigned int Length,signed char *const OutStr)
{
    Status_t RetVal = N_OK;
    unsigned char Iterator = 0;

    if(EmptyPointer == OutStr)
    {
        printf("InValid Input Pointer !! Can't Handle Null Pointer !!\n");
	RetVal = NullPointer;

    }
    else
    {
        for(Iterator =0; Iterator < Length ; Iterator++)
	{
	    OutStr[Iterator] = ReceviedStr[Iterator];
	}
	RetVal = OK;

    }


    return (RetVal);
}





static Status_t Usre_Option(const signed char UserArray[],const signed char TempArray[])
{
	Status_t RetValue = OK;
	register unsigned int Iterator =0;
	for(Iterator =0 ; Iterator < TempArraySize ; Iterator++)
	{
	    if(UserArray[Iterator] != TempArray[Iterator])
	    {
		RetValue = N_OK;
		break;
	    }
	    else {/* Nothing */}
	}

	return (RetValue);
}




