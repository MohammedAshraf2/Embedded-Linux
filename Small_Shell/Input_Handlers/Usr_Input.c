/*
 * File:      Usr_Input.c
 * Author:    Elsayaad
 * Linked In: https://www.linkedin.com/in/mohamed-elsayaad2112/
 * Git Hub:   https://github.com/MohammedAshraf2
 * Created on Octobar 9, 2022, 7:31 PM
 */

 /************** Include Section ****************/
#include "Usr_Input.h"

/********** Data Type Declaration **************/

char *BuiltIn_Array[2] = {"set","export"}; //Hold The Names of BuiltIn Features to use it later with User Input Check Function.

/************** Static Function Decleration Section ****************/

static Std_ReturnType Space_Handler(char *_User_Str,unsigned int *_Counter);

static Std_ReturnType Str_File_Handler(char *_User_Str,char *_Str_File,unsigned int *_Counter,unsigned int *_flag);

static Std_ReturnType Arg_File_Handler(char *_User_Str,char (* const _Str_Arg)[20],unsigned int *_Counter,
                                       unsigned int *_Ret_Counter);

static Std_ReturnType Slach_Handler(char *_User_Str,unsigned int _Counter,unsigned int *_Last_Slash);

static Std_ReturnType Command_Name_Handler(char *_User_Str,unsigned int _Last_Slash,char (* const _Str_Arg)[20]);

static Std_ReturnType Is_There_aVariable(char *_User_Str, unsigned int _Counter ,char *_ret);

static Std_ReturnType Is_Set_Or_Exp(char *_User_Str,user_choice_t *_ret);

/************** Functions Definations ****************/

/**
 * @brief          : Interface to handle user input and any situation of inputs.
 * @param _User_Str: Pointer to char hold the user input.
 * @param _Str_File: Pointer to char will hold command path.
 * @param _Str_Arg : Pointer to array hold the arguments of command.
 * @param _flag    : Pointer hold value neither 0 or 1.
 * @return         :
 *                  E_OK     : Interface Done Successfully.
 *                  E_NOT_OK : Interface Didn't work as predicted.
 */

Std_ReturnType Input_Handler(char *_User_Str,char *_Str_File,char (*_Str_Arg)[20],unsigned int *_flag)
{
    Std_ReturnType l_Ret = E_OK;
    static unsigned int l_Counter =ZERO_INIT;
    unsigned int l_F_Counter =ZERO_INIT, l_File_Length =ZERO_INIT,l_Argu_Counter =ZERO_INIT,l_Last_Slash =ZERO_INIT;
    int l_Status =ZERO_INIT, l_Fork =ZERO_INIT,l_Pid =ZERO_INIT,l_Exp_Counter =ZERO_INIT;
    char l_Variable_Flag =0;
    user_choice_t l_user_ret = OTHER;
    Space_Handler(_User_Str,&l_Counter);
    l_F_Counter = l_Counter;
    //First Case execute by path.
    if( '/' == _User_Str[l_Counter])
    {
        Slach_Handler(_User_Str,l_Counter,&l_Last_Slash);               //get the location of last slash.
        Command_Name_Handler(_User_Str,l_Last_Slash,_Str_Arg);          //get the name of command after last slash.
        Str_File_Handler(_User_Str,_Str_File,&l_Counter,_flag);         //get the path from user input.
        Arg_File_Handler(_User_Str,_Str_Arg,&l_Counter,&l_Argu_Counter);//get the arguments.
        l_Fork = fork();
        if(l_Fork < ZERO_INIT)
        {
            printf("Fork Failled !!\n");
        }
        else if(l_Fork > ZERO_INIT)
        {
            l_Pid = wait(&l_Status);
            if(l_Pid < ZERO_INIT)
            {
                printf("Wait Failled !!\n");
            }
            else
            {/* Nothing */}

        }
        else if(l_Fork ==ZERO_INIT)
        {
            Execute_Path(_Str_File,_Str_Arg,NULL,l_Argu_Counter); // Execute program by path.
        }
        memset(_Str_Arg,'\0',20);
        memset(_User_Str,'\0',l_Counter);
        memset(_Str_File,'\0',40);
        l_Counter =ZERO_INIT;
        l_Ret = E_OK;
    }
    else
    {
        //Check if = is there to store new variable.
        Is_There_aVariable(_User_Str,l_Counter,&l_Variable_Flag);
        //if 1 then True and add var if 0 then move to other condition.
        if( 1 == l_Variable_Flag)
        {
            Check_And_Add_Var(_User_Str);
        }
        else if( ZERO_INIT == l_Variable_Flag)
        {
            Is_Set_Or_Exp(_User_Str,&l_user_ret);
            if(OTHER == l_user_ret)
            {
                Slach_Handler(_User_Str,l_Counter,&l_Last_Slash);
                Command_Name_Handler(_User_Str,l_Last_Slash,_Str_Arg);
                Str_File_Handler(_User_Str,_Str_File,&l_Counter,_flag);
                Arg_File_Handler(_User_Str,_Str_Arg,&l_Counter,&l_Argu_Counter);
                l_Fork = fork();
                if(l_Fork < ZERO_INIT)
                {
                    printf("Fork Failled !!\n");
                }
                else if(l_Fork > ZERO_INIT)
                {
                    l_Pid = wait(&l_Status);
                    if(l_Pid < ZERO_INIT)
                    {
                        printf("Wait Failled !!\n");
                    }
                    else
                    {/* Nothing */}

                }
                else if(l_Fork ==ZERO_INIT)
                {
                    Execute_Command(_Str_File,_Str_Arg,l_Argu_Counter);
                }
                memset(_Str_Arg,'\0',20);
                memset(_User_Str,'\0',l_Counter);
                memset(_Str_File,'\0',40);
                l_Counter =ZERO_INIT;
                l_Ret = E_OK;
            }
            else if(SET == l_user_ret)
            {
                Print_Var();
                l_Ret = E_OK;
            }
            else if(EXPORT == l_user_ret)
            {
                Space_Handler(_User_Str,&l_Exp_Counter);
                printf("l_Counter = %i\n",l_Exp_Counter);
                Export_Var(_User_Str,l_Exp_Counter+EXPORT_OFFSET);
                l_Ret = E_OK;
            }
            else{ /* Nothing */}

        }
        else
        {
            printf("Unkown Yet :))\n");
        }

    }


    return (l_Ret);
}

/************** Helper Functions Definations ****************/

/**
 * @brief          : Interface to handle user input spaces, it eleminates spaces by avoiding it and return index of first char in string.
 * @param _User_Str: Pointer to char hold the user input.
 * @param _Counter : Pointer to unsigned int will return the index of first char in user input string.
 * @return         :
 *                  E_OK     : Interface Done Successfully.
 *                  E_NOT_OK : Interface Didn't work as predicted.
 */

static Std_ReturnType Space_Handler(char *_User_Str,unsigned int *_Counter)
{
    Std_ReturnType l_Ret = E_OK;
    unsigned int Counter =0;
    if((NULL == _User_Str) || (NULL == _Counter))
    {
        l_Ret = E_NOT_OK;
    }
    else
    {
        Counter = *_Counter;
        while( (_User_Str[Counter]== ' ') && (_User_Str[Counter] != '\0'))
        {
              Counter++;
        }
        *(_Counter) = Counter;
        l_Ret = E_OK;

    }

    return (l_Ret);
}

/**
 * @brief          : Interface to handle Path of command if user entered path like this /usr/bin/etc.. .
 * @param _User_Str: Pointer to char hold the user input.
 * @param _Str_File: Pointer to char hold the Command path.
 * @param _Counter : Pointer hold index of first char in user string.
 * @param _flag    : Pointer hold value neither 0 or 1.
 * @return         :
 *                  E_OK     : Interface Done Successfully.
 *                  E_NOT_OK : Interface Didn't work as predicted.
 */


static Std_ReturnType Str_File_Handler(char *_User_Str,char *_Str_File,unsigned int *_Counter,unsigned int *_flag)
{
    Std_ReturnType l_Ret = E_OK;
    unsigned int l_S_Counter = ZERO_INIT;
    unsigned int l_Counter_Temp = 0;
    if((NULL ==  _User_Str) || (NULL == _Str_File) || (NULL == _Counter) || (NULL == _flag))
    {
        l_Ret = E_NOT_OK;
    }
    else
    {
        for( l_Counter_Temp = *_Counter; _User_Str[l_Counter_Temp] != ' ';(l_Counter_Temp)++)
        {
            if(('\0' != _User_Str[l_Counter_Temp]) && (ZERO_INIT == *_flag))
            {
                _Str_File[l_S_Counter] = _User_Str[l_Counter_Temp];
                l_S_Counter++;
            }
            else
            {
                *_flag =1;
                break;
            }
        }
        *_Counter = l_Counter_Temp;
        l_Ret = E_OK;
    }

    return (l_Ret);
}

/**
 * @brief              : Interface to handle Arguments of commands entred by user.
 * @param _Str_File    : Pointer to char will hold command path.
 * @param _Str_Arg     : Pointer to array hold the arguments of command.
 * @param _Counter     : Pointer hold first index of char in string.
 * @param _Ret_Counter : Pointer hold value which describe how many rows have been added to 2D array, which means how many argument.
 * @return             :
 *                       E_OK     : Interface Done Successfully.
 *                       E_NOT_OK : Interface Didn't work as predicted.
 */


static Std_ReturnType Arg_File_Handler(char *_User_Str,char (* const _Str_Arg)[20],unsigned int *_Counter,
                                       unsigned int *_Ret_Counter)
{
    Std_ReturnType l_Ret = E_OK;
    unsigned int l_Counter_Temp = *_Counter,l_S_Counter=0,l_F_Counter =0;
    if((NULL == _User_Str) || (NULL == _Str_Arg) || (NULL == _Counter))
    {
        l_Ret = E_NOT_OK;
    }
    else
    {
        Space_Handler(_User_Str,_Counter);
        l_Counter_Temp = *_Counter;
        for(l_F_Counter =1; _User_Str[l_Counter_Temp] != '\0' ; l_F_Counter++)
        {
            for(l_S_Counter=0;l_S_Counter < 20; l_S_Counter++)
            {
                if(_User_Str[l_Counter_Temp] != '\0' && _User_Str[l_Counter_Temp] != ' ')
                {
                    _Str_Arg[l_F_Counter][l_S_Counter] = _User_Str[l_Counter_Temp];
                    l_Counter_Temp++;
                }
                else
                {
                   break;
                }
            }
            strcpy(*(_Str_Arg+l_F_Counter)+l_S_Counter,"\0");
            l_Counter_Temp += _User_Str[l_Counter_Temp] != '\0' ? 1 : ZERO_INIT;
        }
        _Str_Arg[l_F_Counter][0] = 0;
        *_Counter = l_Counter_Temp;
        *_Ret_Counter = l_F_Counter;
        l_Ret = E_OK;
    }

    return (l_Ret);
}

/**
 * @brief          : Interface to handle Slashes in user input which would be used to know the index of last slash, and this will help in 
 *                    Known name of command entered in path to sotre it.
 * @param _User_Str  : Pointer to char hold the user input.
 * @param _Counter   : Pointer hold index of first char in user input.
 * @param _Last_Slash: Pointer will return the index of last slash in user input command path.
 * @return           :
 *                      E_OK     : Interface Done Successfully.
 *                      E_NOT_OK : Interface Didn't work as predicted.
 */


static Std_ReturnType Slach_Handler(char *_User_Str,unsigned int _Counter,unsigned int *_Last_Slash)
{
    Std_ReturnType l_Ret = E_OK;
    unsigned int l_Slash_Counter =0;
    if((NULL == _User_Str) || (NULL == _Last_Slash))
    {
        l_Ret = E_NOT_OK;
        *_Last_Slash =0;
    }
    else
    {
        for(l_Slash_Counter = _Counter ; _User_Str[l_Slash_Counter] != ' ' ; l_Slash_Counter++)
        {
            if( '\0' == _User_Str[l_Slash_Counter])
            {
                break;
            }
            else
            {
                if( '/' == _User_Str[l_Slash_Counter])
                {
                    *_Last_Slash = l_Slash_Counter;
                }
                else { /*Nothing */ }
            }
        }
    }

    return (l_Ret);
}

/**
 * @brief            : Interface to handle command name entered user.
 * @param _User_Str  : Pointer to char hold the user input.
 * @param _Last_Slash: Variable hold the index of last slash in user input command path.
 * @param _Str_Arg   : Pointer to array hold the arguments of command.
 * @return           :
 *                      E_OK     : Interface Done Successfully.
 *                      E_NOT_OK : Interface Didn't work as predicted.
 */

static Std_ReturnType Command_Name_Handler(char *_User_Str,unsigned int _Last_Slash,char (* const _Str_Arg)[20])
{
    Std_ReturnType l_Ret = E_OK;
    unsigned int l_File_Counter =0, l_S_Counter =0;
    if((NULL == _User_Str) || (NULL == _Str_Arg))
    {
        l_Ret = E_NOT_OK;
    }
    else
    {
        while( 0 == l_File_Counter)
        {
            for(l_S_Counter =0; l_S_Counter < 20; l_S_Counter++)
            {
                if((' ' != _User_Str[_Last_Slash]) && ('\0' != _User_Str[_Last_Slash]))
                {
                    _Str_Arg[l_File_Counter][l_S_Counter] = _User_Str[_Last_Slash];
                }
                else
                {
                    break;
                }
                _Last_Slash++;
            }
            l_File_Counter =1;
        }
    }

    return (l_Ret);
}

/**
 * @brief            : Interface to know if user try to define local variable by check the presence of '='.
 * @param _User_Str  : Pointer to char hold the user input.
 * @param _Counter   : Variable hold the index of first char in user input.
 * @param _ret       : Pointer to return 1 or 0 if it's Zero it means user didn't try to define variable .
 * @return           :
 *                      E_OK     : Interface Done Successfully.
 *                      E_NOT_OK : Interface Didn't work as predicted.
 */

static Std_ReturnType Is_There_aVariable(char *_User_Str, unsigned int _Counter ,char *_ret)
{
    Std_ReturnType l_Ret = E_OK;

    if((NULL == _User_Str) || (NULL ==  _ret))
    {
        l_Ret = E_NOT_OK;
        *_ret = ZERO_INIT; // Zero means False
    }
    else
    {
        *_ret = ZERO_INIT;
        while('\0' !=_User_Str[_Counter])
        {
            if( '=' == _User_Str[_Counter])
            {
                *_ret =1;
                break;
            }
            else
            { /* Nothing */}
            _Counter++;
        }
    }


    return (l_Ret);
}

/**
 * @brief            : Interface to handle user input to know if it try to display or export local variables.
 * @param _User_Str  : Pointer to char hold the user input.
 * @param _ret       : Pointer to return the user choice @ref user_choice_t.
 * @return           :
 *                      E_OK     : Interface Done Successfully.
 *                      E_NOT_OK : Interface Didn't work as predicted.
 */

static Std_ReturnType Is_Set_Or_Exp(char *_User_Str,user_choice_t *_ret)
{
    Std_ReturnType l_Ret = E_NOT_OK;
    char l_Flag =ZERO_INIT;
    unsigned int l_Counter = ZERO_INIT, l_S_Counter = ZERO_INIT, l_User_Counter = ZERO_INIT, l_User_Temp_C = ZERO_INIT;
    unsigned int l_Length = ZERO_INIT;
    if((NULL == _User_Str) || (NULL == _ret))
    {
        printf("Null Pointer Passed !!\n");
    }
    else
    {
        Space_Handler(_User_Str,&l_User_Counter);
        l_User_Temp_C = l_User_Counter;
        for(l_Counter =ZERO_INIT ; l_Counter < 2 ; l_Counter++)
        {
            if( '\0' == _User_Str[l_User_Temp_C] )
            {
                break ;
            }
            else
            {
                l_User_Temp_C = l_User_Counter ;
            }
            l_Length = strlen(BuiltIn_Array[l_Counter]);
            for(l_S_Counter = ZERO_INIT; l_S_Counter < l_Length ; l_S_Counter++)
            {
                if(('\0' != _User_Str[l_User_Temp_C]))
                {
                    if(*(*(BuiltIn_Array+l_Counter)+l_S_Counter) != _User_Str[l_User_Temp_C])
                    {
                        l_Flag =0;
                        break;
                    }
                    else
                    {
                        l_Flag =1;
                    }
                }
                else
                {

                    if('\0' == _User_Str[l_User_Temp_C])
                    {
                        break;
                    }
                    else { /* Nothing */ }
                }
                l_User_Temp_C++;
            }
            if( ZERO_INIT == l_Flag)
            {
                *_ret = OTHER;
            }
            else
            {
                *_ret = l_Counter == ZERO_INIT ? SET : EXPORT;
                break;
            }

        }
        l_Ret = E_OK;
    }

    return (l_Ret);
}
