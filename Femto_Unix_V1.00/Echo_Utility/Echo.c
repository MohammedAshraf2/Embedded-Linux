/* 
 * File:      Echo.c
 * Author:    Elsayaad
 * Linked In: https://www.linkedin.com/in/mohamed-elsayaad2112/
 * Git Hub:   https://github.com/MohammedAshraf2
 * Created on Octobar 2, 2022, 3:15 PM
 */

/*********** Include Section *****************/
#include <stdio.h>
/*********** Macros Section  *****************/

#define ARRAY_SIZE 1024

int main(int argc, char *argv[])
{
    unsigned int l_Counter =0;

    for(l_Counter =1; l_Counter < argc ; l_Counter++)
    {
        printf("%s ",argv[l_Counter]);
    }
    printf("\n");

    return 0;
}

