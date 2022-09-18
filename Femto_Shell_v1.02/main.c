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
#include <Extentions.h>
/********************* Linking Section End ************************/


/********************* Global Variables Defentation Section Start ************************/

static signed char UserInput[ArraySize] = {'0'};
static signed char ShellOut[ArraySize]  = {'0'};

/********************* Global Variables Defentation Section End ************************/



int main()
{
    unsigned char WhileTerminator =0,Iterator =0;
    unsigned int Length =0, InputNumber=0;
    option_t CompRet = Femto_Exit,RetValu =N_OK;
    printf("Welcome To FemtoShell Application\n");
    
    while(!WhileTerminator)
    {
        printf("Please Enter Command:~/Elsayad$");
        scanf("%[^\n]%*c",UserInput);
	Length = strlen(UserInput);
	CompRet = StrComp(UserInput,Length);

	switch(CompRet)
	{
		case Femto_Exit:
		     printf("The Shell Will Exit Now :)\n");
		     printf("**************************\n");
		     WhileTerminator = 1;
		     break;
		case Femto_Rand:
		     Print_Random();
		     break;
		case Femto_Fact:
		     printf("\nEnter Number Please :");
		     scanf("%d",&InputNumber);
		     getchar();
		     printf("factorial of %i is %i\n",InputNumber,Factorial(InputNumber));
		     InputNumber =0;
		     break;
		case Femto_Fib:
		     printf("\nEnter Number Please :");
                     scanf("%d",&InputNumber);
		     getchar();
                     Print_Fibno(InputNumber);
                     InputNumber =0;
		    
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
    }


    return (0);

}


