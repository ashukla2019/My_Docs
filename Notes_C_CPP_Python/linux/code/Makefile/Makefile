CC = g++.exe
INCLUDE = -I./

all: main

ifeq ("x","y")
target: Dependencies
	rule to make target
endif

main: main.o test.o
	$(CC) -o $@ main.o test.o
	
%.o: %.cpp
	$(CC) $(INCLUDE) -c $<
	
