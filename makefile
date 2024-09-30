all: queen.h queen.cpp main.cpp
	g++ -c queen.cpp
	g++ -c main.cpp
	g++ queen.o main.o -o exec

run: all
	    ./exec

clean: 
	    rm -f *.o
	    rm -f exec