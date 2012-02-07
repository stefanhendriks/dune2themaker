CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=gamerules.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=d2tm

all: $(SOURCES)	$(EXECUTABLE)	

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ -lmingw32 -lSDLmain -lSDL -mwindows 

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ -I . 