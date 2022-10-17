/*
 * File:      variables_handlers.c
 * Author:    Elsayaad
 * Linked In: https://www.linkedin.com/in/mohamed-elsayaad2112/
 * Git Hub:   https://github.com/MohammedAshraf2
 * Created on Octobar 15, 2022, 11:22 PM
 */

/************** Include Section ****************/
 #include "variables_handlers.h"

/********** Data Type Declaration **************/

static var_t *Var_Head = NULL; //Pointer of var_t point to the first vaiable in linked list.

/************** Static Function Decleration Section ****************/

static Std_ReturnType Make_Var(var_t **_Var_Head,char *_User_Str);
static Std_ReturnType Check_Var(char *_User_Str,var_t *_Var_Head);
static Std_ReturnType Add_Var_Data(var_t *_Var_Head,char *_User_Str);
static Std_ReturnType Search_Var(char *_User_Str,var_t *_var,unsigned int _Counter,var_t **_var_ret);

/************** Functions Definations ****************/


/**
 * @brief             : Interface to Check if var is exist or not and add it if it's not exist.
 * @param _User_Str   : Pointer hold user input.
 * @return            :
 *                      E_OK     : Interface Done Successfully.
 *                      E_NOT_OK : Interface Didn't work as predicted.
 */



 Std_ReturnType Check_And_Add_Var(char *_User_Str)
 {
    Std_ReturnType l_Ret = E_NOT_OK;
    Std_ReturnType l_Check_Ret = E_NOT_OK;
    if(NULL == _User_Str)
    {
        l_Ret = E_NOT_OK;
    }
    else
    {
        //Checking part
        l_Check_Ret = Check_Var(_User_Str ,Var_Head);
        if( E_NOT_OK == l_Check_Ret)
        {
            printf("There is Variable with the same name\n");
        }
        else
        {
            //Add Part
            Make_Var(&Var_Head,_User_Str);
            //Add Data
            Add_Var_Data(Var_Head,_User_Str);
        }
    }

    return (l_Ret);
 }

/**
 * @brief             : Interface to print all local variables.
 * @return            :
 *                      E_OK     : Interface Done Successfully.
 *                      E_NOT_OK : Interface Didn't work as predicted.
 */


 Std_ReturnType Print_Var(void)
 {
    Std_ReturnType l_Ret = E_NOT_OK;
    unsigned int l_Counter = ZERO_INIT;
    var_t *l_Var_Head = Var_Head;
    if(NULL == l_Var_Head)
    {
        printf("There arn't variables yet\n");
        printf("Please add some \n");
        l_Ret = E_NOT_OK;
    }
    else
    {
        while(l_Var_Head != NULL)
        {
            printf("Var[%i]-> %s = %s\n",l_Counter,l_Var_Head->NAME,l_Var_Head->VAR_VALUE);
            l_Var_Head = l_Var_Head->Next_Var;
            l_Counter++;
        }
        l_Ret = E_OK;
    }

    return (l_Ret);
 }

/**
 * @brief             : Interface to make local variable enviroment variable .
 * @param _User_Str   : Pointer hold user input.
 * @param _Counter    : Variable hold the index of first char in variable name.
 * @return            :
 *                      E_OK     : Interface Done Successfully.
 *                      E_NOT_OK : Interface Didn't work as predicted.
 */


Std_ReturnType Export_Var(char *_User_Str,unsigned int _Counter)
{
    Std_ReturnType l_Ret = E_NOT_OK;
    Std_ReturnType  l_Search_Result = E_NOT_OK;
    int l_Set_Env = ZERO_INIT;
    var_t *l_Var = NULL;
    if(NULL == _User_Str)
    {
        printf("Null Pointer Passed !!!\n");
        l_Ret = E_NOT_OK;
    }
    else
    {
        l_Search_Result = Search_Var(_User_Str,Var_Head,_Counter,&l_Var);
        if(E_NOT_OK == l_Search_Result)
        {
            printf("Sorry This var doesn't exist\n");
            printf("Please add it first :)\n");
        }
        else
        {
            l_Set_Env = setenv(l_Var->NAME, l_Var->VAR_VALUE, 1);
            if(ZERO_INIT != l_Set_Env)
            {
                printf("Error in SetEnv\n");
            }
            else {}

        }
    }

    return (l_Ret);
}


/************** Helper Functions Definations ****************/

/**
 * @brief             : Interface to Check if var is exist or not.
 * @param _User_Str   : Pointer hold user input.
 * @param _Var_Head   : Pointer to first variable.
 * @return            :
 *                      E_OK     : Interface Done Successfully.
 *                      E_NOT_OK : Interface Didn't work as predicted.
 */



static Std_ReturnType Check_Var(char *_User_Str,var_t *_Var_Head)
{
    Std_ReturnType l_Ret = E_NOT_OK;
    unsigned int l_Counter = ZERO_INIT, l_Var_Counter = ZERO_INIT;
    char l_F_Flag =ZERO_INIT, l_S_Flag = ZERO_INIT;
    if((NULL == _User_Str))
    {
        l_Ret = E_NOT_OK; //Error NULL Pointer
    }
    else
    {
        if(NULL == _Var_Head)
        {
            printf("First Var!!\n");
            l_Ret = E_OK;
        }
        else
        {
            while(_Var_Head != NULL)
            {
                l_Var_Counter = ZERO_INIT;
                for(l_Counter =ZERO_INIT; _User_Str[l_Counter] != '\0' ; l_Counter++)
                {
                    if( ' ' != _User_Str[l_Counter])
                    {
                        if(_Var_Head->NAME[l_Var_Counter] != _User_Str[l_Counter])
                        {
                            printf("Here\n");
                            l_F_Flag++;
                            break;
                        }
                        else
                        {
                            l_Ret = E_NOT_OK;
                            l_Var_Counter++;
                        }
                    }
                    else { /* Nothing */ }
                    if('\0' == _Var_Head->NAME[l_Var_Counter])
                    {
                        break;
                    }
                    else { }

                }
                _Var_Head = _Var_Head->Next_Var;
                l_S_Flag++;
            }
            l_Ret = l_F_Flag == l_S_Flag ? E_OK : E_NOT_OK;

        }

    }


    return (l_Ret);
}


/**
 * @brief             : Interface to Create variable.
 * @param _User_Str   : Pointer hold user input.
 * @param _Var_Head   : Pointer to first variable.
 * @return            :
 *                      E_OK     : Interface Done Successfully.
 *                      E_NOT_OK : Interface Didn't work as predicted.
 */



static Std_ReturnType Make_Var(var_t **_Var_Head,char *_User_Str)
 {
    Std_ReturnType l_ret = E_NOT_OK;
    var_t *l_Var = NULL;
    var_t *l_Last_Var = NULL;
    unsigned int l_Length =ZERO_INIT;
    //Case No Var added yet
    l_Var = (var_t *)malloc(sizeof(var_t));
    if(NULL == l_Var)
    {
        printf("Can't reserve variable malloc!!!\n");
        l_Var = NULL;
        l_ret = E_NOT_OK;
    }
    else
    {
        l_Length         = strlen(_User_Str);
        l_Var->NAME      = (char *)malloc(l_Length*sizeof(char));
        l_Var->VAR_VALUE = (char *)malloc(l_Length*sizeof(char));
        if(NULL == *_Var_Head)
        {
            *_Var_Head = l_Var;
            l_Var->Next_Var = NULL;
        }
        else
        {
            l_Last_Var = *_Var_Head;
            while(l_Last_Var->Next_Var != NULL)
            {
                l_Last_Var = l_Last_Var->Next_Var;
            }
            l_Last_Var->Next_Var = l_Var;
            l_Var->Next_Var = NULL;
        }

        l_ret = E_OK;
    }


    return (l_ret);

 }


/**
 * @brief             : Interface to Check add data to variable.
 * @param _User_Str   : Pointer hold user input.
 * @param _Var_Head   : Pointer to first variable.
 * @return            :
 *                      E_OK     : Interface Done Successfully.
 *                      E_NOT_OK : Interface Didn't work as predicted.
 */

static Std_ReturnType Add_Var_Data(var_t *_Var_Head,char *_User_Str)
{
    Std_ReturnType l_Ret = E_NOT_OK;
    var_t *l_Var_Head = NULL;
    unsigned int l_Counter =ZERO_INIT, l_Var_Counter =ZERO_INIT;
    if(NULL == _User_Str)
    {
        l_Ret = E_NOT_OK;
    }
    else
    {

        l_Var_Head = _Var_Head;
        while(l_Var_Head->Next_Var != NULL)
        {
            l_Var_Head = l_Var_Head->Next_Var;
        }

        for(l_Counter=0; _User_Str[l_Counter] != '='; l_Counter++)
        {
            if(' ' != _User_Str[l_Counter])
            {
                l_Var_Head->NAME[l_Var_Counter] = _User_Str[l_Counter];
                l_Var_Counter++;
            }
            else { /* Nothing */ }
        }

        l_Var_Counter =ZERO_INIT;
        l_Counter++;

        for(l_Counter ;_User_Str[l_Counter] != '\0' ; l_Counter++)
        {
            if(' ' != _User_Str[l_Counter])
            {
                l_Var_Head->VAR_VALUE[l_Var_Counter] = _User_Str[l_Counter];
                l_Var_Counter++;
            }
            else { /* Nothing */}
        }
    }


    return (l_Ret);
}

/**
 * @brief             : Interface to Search for variable which would help in the process of export var.
 * @param _User_Str   : Pointer hold user input.
 * @param _Var        : Pointer to first variable.
 * @param _Counter    : Variable hold index of first char in user input.
 * @param _var_ret    : Double pointer will hold the address of variable which would be exported.
 * @return            :
 *                      E_OK     : Interface Done Successfully.
 *                      E_NOT_OK : Interface Didn't work as predicted.
 */



static Std_ReturnType Search_Var(char *_User_Str,var_t *_var,unsigned int _Counter, var_t **_var_ret)
{
    Std_ReturnType l_Ret = E_OK; // E_OK Means Var was Found.
    unsigned int l_Counter =ZERO_INIT, l_Counter_Hold = ZERO_INIT, l_Flag =ZERO_INIT;
    if(NULL == _User_Str)
    {
        l_Ret = E_NOT_OK; // Means Error and No Var was found.
    }
    else
    {
        while(_var != NULL)
        {
            l_Counter_Hold = 0;
            for(l_Counter =_Counter; _User_Str[l_Counter] != '\0'; l_Counter++)
            {
                if( ' ' != _User_Str[l_Counter])
                {
                    if(_var->NAME[l_Counter_Hold] != _User_Str[l_Counter])
                    {
                        l_Flag =ZERO_INIT;
                        l_Ret = E_NOT_OK; // No Var With this Name.
                        break;
                    }
                    else
                    {
                        l_Flag =1;  //flag to know if it's the right address of var.
                        l_Counter_Hold++;
                    }
                }
                else { /* Nothing */ }
            }
            *_var_ret = l_Flag == 1 ? _var : NULL;
            if(1 == l_Flag)
            {
                l_Ret = E_OK;
                break;
            }
            else
            {
                 _var = _var->Next_Var;
            }

        }

    }


    return (l_Ret);
}

