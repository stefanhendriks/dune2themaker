CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=gamerules.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=d2tm

all:	clean	setup	$(SOURCES)	$(EXECUTABLE)	

setup:
	mkdir bin
	mkdir obj

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o obj/$@ -lmingw32 -lSDLmain -lSDL -mwindows 

.cpp.o:
	$(CC) $(CFLAGS) $< -o obj/$@ -I . 

clean:
	rm -rf bin
	rm -rf obj