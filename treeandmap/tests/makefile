CC = g++
OUT_FILE_NAME = graph

CFLAGS= -g -Wall -std=c++14
INC= -I../src -I../../test_tool 
LIBS= -L../../lib -lUnitTestFrameWork -lTreeAndMap
OUT_DIR=../../output

all: dirmake
	$(CC) $(CFLAGS) $(INC) $(LIBS) *.cpp -o $(OUT_DIR)/$(OUT_FILE_NAME)
		
dirmake:
	@mkdir -p $(OUT_DIR)

clean:
	rm -f $(OUT_DIR)/* Makefile.bak
	rm -r $(OUT_DIR)

rebuild: clean build

