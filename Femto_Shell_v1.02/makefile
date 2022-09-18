.PHONY: Clean
STATICLINK=NO



Femto : StrCpy.o main.o 
ifeq ($(STATICLINK),YES)
	$(MAKE) -C ./Library/
	gcc -static -o Femto *.o  -l:libadds.a -L./Library/
else 
	$(MAKE) -C ./Library/ 
	gcc *.o -o Femto -l:libadds.so -L./Library/
endif

StrCpy.o : StrCpy.c StrCpy.h
	gcc StrCpy.c -c -I./Library/
main.o : main.c StrCpy.h ./Library/Extentions.h
	gcc main.c -c -I./Library/

Clean :
	rm -f *.o

