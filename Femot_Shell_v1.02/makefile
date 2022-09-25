.PHONY: Clean
.PHONY: Uninstall
STATICLINK=YES
LIBRARY=./Library/
STATICPATH=./Library/StaticLib/
DYNAMICPATH=./Library/DynamicLib/

###########################################################

Femto : Helper.o main.o 
ifeq ($(STATICLINK),YES)
	$(MAKE) -C $(LIBRARY) ISSTATIC=YES
	gcc -static -o Femto *.o  -l:libadds.a -L$(STATICPATH)
	$(MAKE) Clean
else 
	$(MAKE) -C $(LIBRARY) ISSTATIC=NO
	gcc *.o -o Femto -l:libadds.so -L$(DYNAMICPATH)
	$(MAKE) Clean
endif

StrCpy.o : Helper.c Helper.h Std_Library.h
	gcc StrCpy.c -c -I$(LIBRARY)
main.o : main.c Helper.h $(LIBRARY)Extentions.h
	gcc main.c -c -I$(LIBRARY)

###########################################################

install: Femto
	cp Femto /usr/bin
	chmod a+x /usr/bin/Femto
	chmod og-w /usr/bin/Femto
ifeq ($(STATICLINK),YES)
	echo " Femto Instalation done"
else
	cp $(DYNAMICPATH)libadds.so /usr/lib/x86_64-linux-gnu/
endif

Uninstall:
	rm -f /usr/bin/Femto /usr/lib/x86_64-linux-gnu/libadds.so
	echo "Femto Was Uninstalled"


Clean :
	rm -f *.o

