.PHONY: Clean
LAYER_ONE_PATH=./Input_Handlers/
LAYER_TWO_PATH=./Input_Handlers/BuiltIn/
CC=gcc
OBJS=small_shell.o ./Input_Handlers/Usr_Input.o ./Input_Handlers/BuiltIn/execute_program.o ./Input_Handlers/BuiltIn/variables_handlers.o
TARGET=small_shell
###############################################
$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
	$(MAKE) Clean
	$(MAKE) -C $(LAYER_ONE_PATH) Clean
	$(MAKE) -C  $(LAYER_TWO_PATH) Clean




variables_handlers.o : variables_handlers.c
	$(CC) $(LAYER_TWO_PATH)$< -c $(LAYER_TWO_PATH)$@


execute_program.o : execute_program.c
	$(CC) $(LAYER_TWO_PATH)$< -c $(LAYER_TWO_PATH)$@

Usr_Input.o : Usr_Input.c
	$(CC) $(LAYER_ONE_PATH)$< -c $(LAYER_ONE_PATH)$@

small_shell.o : small_shell.c
	$(CC) $< -c $@


Clean :
	rm *.o
###############################################


