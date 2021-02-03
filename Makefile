CC=g++
CCFLAGS=-g -std=c++11 -Wall -Wextra -pedantic

BINARIES=obj/model.o obj/formula.o obj/visualization.o

EXECUTABLE_NAME=simulation

all: obj sim

obj:
	mkdir -p obj

sim: $(BINARIES)
	$(CC) $(CCFLAGS) -o $(EXECUTABLE_NAME) $(BINARIES) -funroll-loops -lncurses

###############################################

obj/model.o: src/model.cpp src/model.h
	$(CC) $(CCFLAGS) -c src/model.cpp -o obj/model.o

obj/formula.o: src/formula.cpp src/formula.h
	$(CC) $(CCFLAGS) -c src/formula.cpp -o obj/formula.o

obj/visualization.o: src/visualization.cpp src/visualization.h
	$(CC) $(CCFLAGS) -c src/visualization.cpp -o obj/visualization.o

################################################

run: obj sim
	./simulation

################################################

clean:
	rm -f simulation; rm -rf obj
