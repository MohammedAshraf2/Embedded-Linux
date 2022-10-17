/*
 * File:      Usr_Input.c
 * Author:    Elsayaad
 * Linked In: https://www.linkedin.com/in/mohamed-elsayaad2112/
 * Git Hub:   https://github.com/MohammedAshraf2
 * Created on Octobar 9, 2022, 8:01 PM
 */


/************** Include Section ****************/
#include "execute_program.h"


/********** Data Type Declaration **************/
static char *argv[] = {NULL}; // Array of pointers to hold address of arguments entred by user.

/************** Static Function Decleration Section ****************/

static Std_ReturnType Arg_Handler(char (*_Str_Arg)[20],char *argv[], unsigned int _Argu_Counter);

/************** Functions Definations ****************/

/**
 * @brief              : Interface to Execute command entred by user with the known of command path.
 * @param _pathname    : Pointer to char hold the path of command.
 * @param _Str_Arg     : Pointer to array hold the arguments of command.
 * @param envp         : Array of pointer to hold enviroment variables.
 * @param _Argu_Counter: Variable hold the numbers of arguments.
 * @return             :
 *                      E_OK     : Interface Done Successfully.
 *                      E_NOT_OK : Interface Didn't work as predicted.
 */

Std_ReturnType Execute_Path(const char *_Pathname, char (*_Str_Arg)[20],
                  char *const envp[], unsigned int _Argu_Counter)
{
    Std_ReturnType l_Ret = E_OK;
    //char *Arg_1[] = {"ls","-l",0};
    if(ZERO_INIT != _Argu_Counter)
    {
        Arg_Handler(_Str_Arg,argv,_Argu_Counter);
    }
    else { /* Nothing */}

    int l_Exec =ZERO_INIT;
    l_Exec = execve(_Pathname,argv,NULL);

     if(l_Exec < ZERO_INIT)
     {
        printf("Exec Failled !!\n");
        l_Ret = E_NOT_OK;
     }
     else {/*NoThing */}
    return (l_Ret);
}

/**
 * @brief              : Interface to Execute command entred by user with the known of only it's name.
 * @param _File        : Pointer to char hold the Name of command.
 * @param _Str_Arg     : Pointer to array hold the arguments of command.
 * @param _Argu_Counter: Variable hold the numbers of arguments.
 * @return             :
 *                      E_OK     : Interface Done Successfully.
 *                      E_NOT_OK : Interface Didn't work as predicted.
 */

Std_ReturnType Execute_Command(const char *_File, char (*const _Str_Arg)[20],
                               unsigned int _Argu_Counter)
{
    Std_ReturnType l_Ret = E_OK;
    int l_Exec_Ret =ZERO_INIT;
    if((NULL == _File) || (NULL == _Str_Arg))
    {
        l_Ret = E_NOT_OK;
    }
    else
    {
        if(ZERO_INIT != _Argu_Counter)
        {
            Arg_Handler(_Str_Arg,argv,_Argu_Counter);
        }
        else { /* Nothing */}

        l_Exec_Ret = execvp(_File, argv);
        if(l_Exec_Ret < ZERO_INIT)
        {
            printf("Command Failed to execute \n");
            l_Ret = E_NOT_OK;
        }
        else
        { /* Nothing */}

    }


    return (l_Ret);
}

/**************Static Functions Definations ****************/



/**
 * @brief              : Interface to Handle Argument entered by user make it in form suitable to be passed to exec functions.
 * @param _Str_Arg     : Pointer to array hold the arguments of command.
 * @param argv         : Array of pointer will hold the address of arguments that exist in 2D array.
 * @param _Argu_Counter: Variable hold the numbers of arguments.
 * @return             :
 *                      E_OK     : Interface Done Successfully.
 *                      E_NOT_OK : Interface Didn't work as predicted.
 */



static Std_ReturnType Arg_Handler(char (*_Str_Arg)[20],char *argv[], unsigned int _Argu_Counter)
{
    Std_ReturnType l_Ret = E_OK;
    unsigned int l_Arg_Counter =ZERO_INIT,l_Str_Counter =1;
    argv[ZERO_INIT] = &_Str_Arg[ZERO_INIT][ZERO_INIT];
    for(l_Arg_Counter =1;l_Arg_Counter <= _Argu_Counter ; l_Arg_Counter++)
    {
        argv[l_Arg_Counter] = &_Str_Arg[l_Str_Counter][ZERO_INIT];
        l_Str_Counter++;
    }
    argv[l_Arg_Counter-1] = ZERO_INIT;


    return (l_Ret);
}
