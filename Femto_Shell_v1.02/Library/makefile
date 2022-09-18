.PHONY: Clean
ISSTATIC = NO

ifeq ($(ISSTATIC),YES)
libadds.a : fibonacci.o rand.o fact.o
		ar -rs libadds.a *.o
else
libadds.sh : fibonacci.o rand.o fact.o
	gcc -shared *.o -o libadds.so
endif

%.o : %.c
ifeq ($(ISSTATIC),YES)
	gcc $@ -c $<
else
	gcc $@ -c -fPIC $<
endif


Clean :
	rm  *.o

