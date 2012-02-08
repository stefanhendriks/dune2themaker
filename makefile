CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=gamerules.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=d2tm


clean:	clean-main	clean-test

clean-main:
	rm -rf bin\main

clean-test:
	rm -rf bin\test