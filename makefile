CC=g++
CFLAGS=-Wall

# MAIN properties
SRC=src/main/cpp
INCLUDE=src/include
BIN=bin/main
RESOURCES=src/main/resources
LIB=lib

# TEST properties
SRC_TEST=src/test
BIN_TEST=bin/test
RESOURCES_TEST=src/test/resources

all: clean compile compile-test copy-resources copy-libraries

bin: clean compile copy-resources copy-libraries

copy-libraries:
	cp $(LIB)/*.* $(BIN)

copy-resources:
	cp -R $(RESOURCES)/ $(BIN)

compile: clean-main prepare-main
	$(CC) $(SRC)/*.cpp $(SRC)/domain/*.cpp $(SRC)/states/*.cpp -I$(INCLUDE) -I$(INCLUDE)/domain -I$(INCLUDE)/states -o $(BIN)/d2tm -lmingw32 -lSDLmain -lSDL $(CFLAGS)

compile-test: clean-test prepare-test
	$(CC) $(SRC_TEST)/*.cpp -I$(INCLUDE) -o $(BIN_TEST)/tests $(CFLAGS)

clean:	clean-main	clean-test

clean-main:
	rm -rf bin\main

prepare-main:
	mkdir bin\main

clean-test:
	rm -rf bin\test

prepare-test:
	mkdir bin\test
