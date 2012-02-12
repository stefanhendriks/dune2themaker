CC=g++
CFLAGS=-Wall

# MAIN properties
SRC=src/main/cpp
SRC_MAIN_RUNNER_DIR=src/main
INCLUDE=src/include
BIN=bin/main
RESOURCES=src/main/resources
LIB=lib

# TEST properties
SRC_TEST=src/test/cpp
BIN_TEST=bin/test
RESOURCES_TEST=src/test/resources

all: clean compile compile-test copy-resources copy-libraries

bin: clean-main compile copy-resources copy-libraries

test: clean-test compile-test copy-test-resources copy-test-libraries

copy-libraries:
	cp $(LIB)/*.* $(BIN)

copy-resources:
	cp -R $(RESOURCES)/ $(BIN)

copy-test-resources:
	cp -R $(RESOURCES)/ $(BIN_TEST)

copy-test-libraries:
	cp $(LIB)/*.* $(BIN_TEST)

compile: clean-main prepare-main
	$(CC) $(SRC_MAIN_RUNNER_DIR)/*.cpp $(SRC)/*.cpp $(SRC)/domain/*.cpp $(SRC)/states/*.cpp -I$(INCLUDE) -I$(INCLUDE)/domain -I$(INCLUDE)/states -o $(BIN)/d2tm -lmingw32 -lSDLmain -lSDL $(CFLAGS)

compile-test: clean-test prepare-test
	$(CC) $(SRC_TEST)/*.cpp $(SRC)/*.cpp $(SRC)/domain/*.cpp $(SRC)/states/*.cpp -I$(INCLUDE) -I$(INCLUDE)/domain -I$(INCLUDE)/states -o $(BIN_TEST)/tests -lmingw32 -lSDLmain -lSDL $(CFLAGS)

clean:	clean-main	clean-test

clean-main:
	rm -rf bin\main

prepare-main:
	mkdir bin\main

clean-test:
	rm -rf bin\test

prepare-test:
	mkdir bin\test
