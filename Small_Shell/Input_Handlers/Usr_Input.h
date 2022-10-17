/*
 * File:      Usr_Input.h
 * Author:    Elsayaad
 * Linked In: https://www.linkedin.com/in/mohamed-elsayaad2112/
 * Git Hub:   https://github.com/MohammedAshraf2
 * Created on Octobar 9, 2022, 7:30 PM
 */

 #ifndef _USR_INPUT_H
 #define _USR_INPUT_H

/************** Include Section ****************/
#include "./BuiltIn/execute_program.h"
#include "./BuiltIn/variables_handlers.h"
/********** Macro Declaration *****************/


/********** Macro functions Declaration **************/
#define EXPORT_OFFSET 7

/********** Data Type Declaration **************/

typedef enum
{
    SET=1,
    EXPORT,
    OTHER
}user_choice_t;

/********** Functions Prototypes **************/
Std_ReturnType Input_Handler(char *_User_Str,char *_Str_File,char (*_Str_Arg)[20],unsigned int *_flag);

#endif
