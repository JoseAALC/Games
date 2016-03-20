CONFIG = -std=c++11

all:start
	./a.out

start:State.o main.o game.o
	g++ -g main.o State.o game.o $(CONFIG)

State.o:State.cpp
	g++ -g -c State.cpp $(CONFIG)

main.o:main.cpp
	g++ -g -c main.cpp $(CONFIG) 

game.o:game.cpp
	g++ -g -c game.cpp $(CONFIG) 

clean:
	rm *.o 