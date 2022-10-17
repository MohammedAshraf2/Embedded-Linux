/*
 * File:      Readme.txt
 * Author:    Elsayaad
 * Linked In: https://www.linkedin.com/in/mohamed-elsayaad2112/
 * Git Hub:   https://github.com/MohammedAshraf2
 * Created on Octobar 17, 2022, 3:39 AM
 */


Welcome To my Small shell, this shell has features like define local variables,execute any command like normal shell by two ways first by pathother by command name like ( ls -l) || (/usr/bin/ls -l) both are valid in this tiny shell and so for the rest of any command.
By define local variable in this shell you can make them enviroment variables by write export (Name of variable) like : (export x).
Define local variable is so easy only write (Name of var = Value).

To start This shell first type (make) to generate elf file, then simply write this in your shell ./small_shell.
the built in commands in this shell are:
1.set    : This display all local variables in the shell.
2.export : Like it was said before it's for make local vaiable enviroment variables.
*******************
The Project is divided into 3 folders:
1. Small_Shell   : you will find the small_shell.c in it which call only one function that it Input_Handler.
2. Input_Handler : you will find the main structure of shell in it in (Usr_Input.c)
3. BuiltIn       : you will find the ground structure of shell in it (execute_program.c && variables_handlers.c).
*******************
