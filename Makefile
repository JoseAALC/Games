CONFIG = -std=c++11


all:start
	./a.out

start:State.o main.o game.o movement.o
	g++ -pg main.o State.o game.o movement.o $(CONFIG) 

State.o:State.cpp
	g++ -pg -c State.cpp $(CONFIG)

main.o:main.cpp
	g++ -pg -c main.cpp $(CONFIG) 

game.o:game.cpp
	g++ -pg -c game.cpp $(CONFIG) 

movement.o:movement.cpp			
	g++ -pg -c movement.cpp $(CONFIG) 
clean:
	rm *.o 