include ../makefile.inc

OUT_FILE_NAME = libUnitTestFrameWork.a
CFLAGS= $(DEFAULT_FLAGS) -c

OBJ_DIR= $(TARGET_TEST_PATH)/obj
OUT_DIR= $(TARGET_TEST_PATH)/lib

$(OUT_FILE_NAME): $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(wildcard *.cpp))
	ar rsv $(OUT_DIR)/$@ $^

#Compiling every *.cpp to *.o
$(OBJ_DIR)/%.o: %.cpp dirmake
	$(CC) -c $(INC) $(CFLAGS) -o $@  $<
	
dirmake:
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OBJ_DIR)
	
clean:
	rm -f $(OBJ_DIR)/*.o $(OUT_DIR)/$(OUT_FILE_NAME) Makefile.bak

rebuild: clean build
