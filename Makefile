CC="/usr/bin/g++-4.4"
CFLAGS=-Wall -fexceptions -g -Iinclude -c
EXEC=AIPaths
TOP := $(dir $(lastword $(MAKEFILE_LIST)))
LIB := $(TOP)SFML-2.3.2/lib
all: Main #Main.o Agent.o GameState.o Map.o


Main: Main.o Agent.o GameState.o Map.o
	LD_LIBRARY_PATH=$(LIB) $(CC) -o $(TOP)$(EXEC) Main.o GameState.o Agent.o Map.o -L$(LIB) -lsfml-system -lsfml-win\
	dow -lsfml-graphics


Main.o: main.cpp
	$(CC) $(CFLAGS) $(TOP)main.cpp -o Main.o

Agent.o: src/Agent.cpp
	$(CC) $(CFLAGS) $(TOP)src/Agent.cpp -o Agent.o

GameState.o: src/GameState.cpp
	$(CC) $(CFLAGS) $(TOP)src/GameState.cpp -o GameState.o

Map.o: src/Map.cpp
	$(CC) $(CFLAGS) $(TOP)src/Map.cpp -o Map.o

clean:
	rm *.o $(TOP)$(EXEC)
