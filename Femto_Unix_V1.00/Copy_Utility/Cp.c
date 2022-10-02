/* 
 * File:      Cpy.c
 * Author:    Elsayaad
 * Linked In: https://www.linkedin.com/in/mohamed-elsayaad2112/
 * Git Hub:   https://github.com/MohammedAshraf2
 * Created on Octobar 2, 2022, 3:35 PM
 */

/*********************** Include Section **********************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


/*********************** Macros Section **********************/
#define BUFF_SIZE            (100)
#define ZERO_INIT            (0)
#define FUNC_ERROR           (-1)
#define ARGV_Element_1       (1)
#define ARGV_Element_2       (2)

int main(int argc, char *argv[])
{
    signed char l_Close_Flag =ZERO_INIT; //ZERO_INIT the process done successfully. 
    signed int l_Read_Flag = ZERO_INIT, l_Write_Flag =ZERO_INIT; // ZERO_INIT  Means End of file.
    char Buff_Array[BUFF_SIZE] = {ZERO_INIT};
    signed int l_Src_File_Descriptor = ZERO_INIT, l_Dest_File_Descriptor = ZERO_INIT;
    unsigned int l_Buff_Length =0;

    l_Dest_File_Descriptor = open(argv[ARGV_Element_2],O_CREAT | O_WRONLY);
    l_Src_File_Descriptor  = open(argv[ARGV_Element_1] , O_RDONLY);
    
    while(!ZERO_INIT)
    {
        l_Read_Flag = read(l_Src_File_Descriptor,Buff_Array,BUFF_SIZE);
    
        if((FUNC_ERROR == l_Read_Flag))
        {
            printf("Error Has Occured \n");
            break;
        }
        else if(ZERO_INIT == l_Read_Flag)
        {
            printf("Read has been done\n");
            break;
        }
        else if(l_Read_Flag > 0)
        {
            l_Write_Flag =  write(l_Dest_File_Descriptor,Buff_Array,l_Read_Flag);//Read Function if success return number of bytes that were read.
            if(FUNC_ERROR == l_Write_Flag)
            {
                printf("Error In Write Func \n");
                break;
            }
            else { /* No Thing */ }
            
        }
        else
        {
            printf("Error Undefined \n");
            break;
        }


    }
    l_Close_Flag  = close(l_Dest_File_Descriptor);
    l_Close_Flag |= close(l_Src_File_Descriptor);
    
    switch(l_Close_Flag)
    {
        case 0:
            printf("Close Filles Successfully\n");
            break;
        case -1:
            printf("Close Files Falied \n");
            break;
        default :
            /* No Thing */
            break;
    }


    

    return 0;
}

