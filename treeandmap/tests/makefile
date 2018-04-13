include ../../makefile.inc

OUT_FILE_NAME = graph
CFLAGS= $(DEFAULT_FLAGS)
INC= -I../src -I../../test_tool 
LIBS= -L$(TARGET_PATH)/lib -lUnitTestFrameWork -lTreeAndMap
OUT_DIR= $(TARGET_PATH)/output

all: dirmake
	$(CC) $(CFLAGS) $(INC) $(LIBS) *.cpp -o $(OUT_DIR)/$(OUT_FILE_NAME)
		
dirmake:
	@mkdir -p $(OUT_DIR)

clean:
	rm -f $(OUT_DIR)/* Makefile.bak
	rm -r $(OUT_DIR)

rebuild: clean build

