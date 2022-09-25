.PHONY: Clean
STATICPATH=/home/engmohammedelsayaad/FemtoShell/Library/StaticLib/
DYNAMICPATH=/home/engmohammedelsayaad/FemtoShell/Library/DynamicLib/
ISSTATIC = NO
OBJS=fibonacci.o rand.o fact.o

#######################################################

ifeq ($(ISSTATIC),YES)
libadds.a : $(OBJS)
		ar -rs $(STATICPATH)libadds.a *.o
		$(MAKE) Clean
else
libadds.so : $(OBJS)
		gcc -shared *.o -o $(DYNAMICPATH)libadds.so
		$(MAKE) Clean
endif

%.o : %.c
ifeq ($(ISSTATIC),YES)
	gcc $@ -c $<
else
	gcc $@ -c -fPIC $<
endif

######################################################


Clean :
	rm  *.o

