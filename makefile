CC=g++
CFLAGS=-Wall

SRC=src/main
INCLUDE=src/include
BIN=bin/main
RESOURCES=src/main/resources
LIB=lib

all: compile copy-resources copy-libraries

copy-libraries:
	cp $(LIB)/*.* $(BIN)

copy-resources:
	cp $(RESOURCES)/*.* $(BIN)

compile: clean-main prepare-main
	$(CC) $(SRC)/*.cpp -I$(INCLUDE) -o $(BIN)/d2tm -lmingw32 -lSDLmain -lSDL -mwindows $(CFLAGS)

clean:	clean-main	clean-test

clean-main:
	rm -rf bin\main

prepare-main:
	mkdir bin\main

clean-test:
	rm -rf bin\test