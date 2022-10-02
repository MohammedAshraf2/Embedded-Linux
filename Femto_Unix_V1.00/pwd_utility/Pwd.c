/*
 * File:      Pwd.c
 * Author:    Elsayaad
 * Linked In: https://www.linkedin.com/in/mohamed-elsayaad2112/
 * Git Hub:   https://github.com/MohammedAshraf2
 * Created on Octobar 2, 2022, 2:30 PM
 */


/*************** Include Section ********************/
#include <stdio.h>
#include <unistd.h>


int main()
{
    char *Ptr =NULL; // Pointer to save return of getcwd in it.
    char Buff[100] = {0}; //Array to store the current working directory path.

    Ptr = (char *)getcwd(Buff,100);
    if(NULL == Ptr)
    {
        printf("Sorry Try Again\n");
    }
    else
    {
        printf("%s\n",Buff);
        Ptr = NULL;
    }

    return 0;
}
