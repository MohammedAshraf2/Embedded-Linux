/*
 * File:      execute_program.h
 * Author:    Elsayaad
 * Linked In: https://www.linkedin.com/in/mohamed-elsayaad2112/
 * Git Hub:   https://github.com/MohammedAshraf2
 * Created on Octobar 9, 2022, 8:00 PM
 */

 #ifndef _EXECUTE_PROGRAM_H
 #define _EXECUTE_PROGRAM_H

/************** Include Section ****************/

#include "Standard.h"

/********** Macro Declaration *****************/

/********** Macro functions Declaration **************/

/********** Data Type Declaration **************/

/********** Functions Prototypes **************/


Std_ReturnType Execute_Path(const char *_Pathname, char (*const _Str_Arg)[20],
                  char *const envp[], unsigned int _Argu_Counter);


Std_ReturnType Execute_Command(const char *_File, char (*const _Str_Arg)[20],
                               unsigned int _Argu_Counter);


#endif
