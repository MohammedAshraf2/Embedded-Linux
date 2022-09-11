/**
*******************************************
* @file             : Readme.txt
* @author           : MohammedElsayaad
* @Date             : 9/9/2022
*******************************************
*/
# Embedded-Linux
This Will contain incremental project update for my journy with linux.

The commands used are:

vim				 (to create file)
gcc *.c -c			 (Creating the object files)
gcc *.o -o FemtoShellApp	 (Creating the exe file)
cd				 (alot of times :) )
pwd
mkdir
rm
mv

Special cases:

When the header file StrCpy.h wasn't in the same location as main.c i used the next command but after that
i prefered moving it with (mv) to the same location as main.c

gcc *.o -o FemtoShellApp -I ./ECU
