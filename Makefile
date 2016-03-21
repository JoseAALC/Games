CONFIG = -std=c++11
GRAPHIC =  -lsfml-graphics -lsfml-window -lsfml-system

all:start
	./a.out

start:State.o main.o game.o gui.o TextureHolder.o
	g++ -g main.o State.o game.o gui.o TextureHolder.o $(CONFIG) $(GRAPHIC)

State.o:State.cpp
	g++ -g -c State.cpp $(CONFIG)

main.o:main.cpp
	g++ -g -c main.cpp $(CONFIG) 

game.o:game.cpp
	g++ -g -c game.cpp $(CONFIG) 

gui.o:gui.cpp
	g++ -g -c gui.cpp $(CONFIG) $(GRAPHIC)	

TextureHolder.o:TextureHolder.cpp
	g++ -g -c TextureHolder.cpp $(CONFIG) $(GRAPHIC)		

clean:
	rm *.o 