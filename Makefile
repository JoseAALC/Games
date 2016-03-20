CONFIG = -std=c++11

all:start

start:State.o main.o
	g++ -g main.o State.o  $(CONFIG)

State.o:State.cpp
	g++ -g -c State.cpp $(CONFIG)

main.o:main.cpp
	g++ -g -c main.cpp $(CONFIG) 


clean:
	rm *.o a.out 
