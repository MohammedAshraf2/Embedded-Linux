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


Status_t StrComp(const signed char ReceviedStr[],const unsigned int Length)
{
    Status_t RetVal = Continue;
    signed char ExitArray[5] = {'e','x','i','t'};
    unsigned char Iterator =0,ExitValidation = Matched;
    
    if((0 == Length) || (ReceviedStr[0] == '0') || (ReceviedStr[0] == '\0'))
    {
        RetVal = N_Continue;
    }
    else
    {

    	for(Iterator =0; Iterator <Length ; Iterator++)
    	{
	    if(ReceviedStr[Iterator] != ExitArray[Iterator])
	    {
	        ExitValidation = NotMatched;
		break;

	    }
	    else
	    {
	        ExitValidation = Matched;

	    }
    	}
	RetVal = ExitValidation == NotMatched ? Continue : N_Continue;

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






