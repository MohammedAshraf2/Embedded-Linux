/*
 * File:      Small_Shell.c
 * Author:    Elsayaad
 * Linked In: https://www.linkedin.com/in/mohamed-elsayaad2112/
 * Git Hub:   https://github.com/MohammedAshraf2
 * Created on Octobar 9, 2022, 7:10 PM
 */

/************** Include Section ****************/

#include "small_shell.h"

char *Str_User  = "0";                        //Hold The User Input Str
char  Str_File[STR_FILE_SIZE] = {ZERO_INIT};  //Hold User Command path ex:/usr/bin/ls.

int main()
{
    unsigned int l_File_Flag =ZERO_INIT;
    unsigned int l_Length =ZERO_INIT;           //Hold The length of l_str_user.
    char l_Str_Arg[][STR_ARG_SIZE] = {'\0'};    //Hold User Command Arguments ex: -l for ls.
    Std_ReturnType l_Ret = E_OK;
    Str_User = (char *)malloc(1024*sizeof(char)); //Allocate 1024 byte in heap.
    if(NULL == Str_User)
    {
        printf("Malloc failled!!!\n");
    }
    else
    {
        while(OK)
        {

            printf("Small Shell On=> ");
            fgets(Str_User,1024,stdin);
            l_Length = strlen(Str_User);
            if(*Str_User == '\n')
            {
                continue;
            }
            else
            {
                Str_User[strcspn(Str_User, "\n")] = '\0';                       //Handle the new line problem.
                l_File_Flag =ZERO_INIT;
                l_Ret = Input_Handler(Str_User,Str_File,l_Str_Arg,&l_File_Flag);
                if(E_OK != l_Ret)
                {
                    printf("Input Handler Failed!!\n");
                }
                else
                {/* Nothing */}
                l_File_Flag= ZERO_INIT;

            }

        }
        free(Str_User);
    }




    return ZERO_INIT;
}



