CC="/usr/bin/g++"
CFLAGS=-Wall -fexceptions -g -Iinclude -c
EXEC=AIPaths
TOP := $(dir $(lastword $(MAKEFILE_LIST)))
all: Main #Main.o Agent.o GameState.o Map.o


Main: Main.o Agent.o GameState.o Map.o
	$(CC) -o $(TOP)$(EXEC) Main.o GameState.o Agent.o Map.o -lsfml-system -lsfml-window -lsfml-graphics 


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
