/**
*******************************************
* @file             : main.c
* @author           : MohammedElsayaad
* @brief            : This is the main file (Application file), the purpose from it is to simulate the performance of
* 		       Shell by taking input from user as command and display it fro him again, if user entered exit
* 		       the program would stop.
*@Date              : 9 / 9 / 2022
*******************************************
*/


/********************* Linking Section Start ************************/

#include "StrCpy.h"

/********************* Linking Section End ************************/


/********************* Global Variables Defentation Section Start ************************/

static signed char UserInput[ArraySize] = {'0'};
static signed char ShellOut[ArraySize]  = {'0'};

/********************* Global Variables Defentation Section End ************************/



int main()
{
    unsigned char WhileTerminator =0,Iterator =0;
    unsigned int Length =0;
    Status_t CompRet = Continue,RetValu =N_OK;
    printf("Welcome To FemtoShell Application\n");
    
    while(!WhileTerminator)
    {
        printf("Please Enter Command:~/Elsayad$");
        scanf("%[^\n]%*c",UserInput);
	Length = strlen(UserInput);
	CompRet = StrComp(UserInput,Length);

	switch(CompRet)
	{
		case N_Continue:
		     printf("The Shell Will Exit Now :)\n");
		     printf("**************************\n");
		     WhileTerminator = 1;
		     break;
		default :
		    RetValu = StrCpy_t(UserInput,Length,ShellOut);
		    if(N_OK == RetValu)
		    {
		        printf("Error Please Try Again !!\n");
		    }
		    else
		    {
		         printf("The Command Is ==> ");
                         for(Iterator =0; Iterator < Length; Iterator++)
			 {
                             printf("%c",ShellOut[Iterator]);
                         }
	
			 printf("\n");

		    }
		    break;	    
	}
	 UserInput[0] = '0';
	 ShellOut[0]  = '0';

    }


    return (0);

}


