/*
 * File:      variables_handlers.h
 * Author:    Elsayaad
 * Linked In: https://www.linkedin.com/in/mohamed-elsayaad2112/
 * Git Hub:   https://github.com/MohammedAshraf2
 * Created on Octobar 15, 2022, 11:21 PM
 */

 #ifndef _VARIABLE_HANDLER_H
 #define _VARIABLE_HANDLER_H

/************** Include Section ****************/
#include "Standard.h"

/********** Macro Declaration *****************/


/********** Macro functions Declaration **************/


/********** Data Type Declaration **************/
typedef struct var
{
    char *NAME;
    char *VAR_VALUE;
    struct var *Next_Var;
}var_t;

/********** Functions Prototypes **************/

Std_ReturnType Check_And_Add_Var(char *_User_Str);
Std_ReturnType Print_Var(void);
Std_ReturnType Export_Var(char *_User_Str,unsigned int _Counter);




 #endif
