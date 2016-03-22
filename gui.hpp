#ifndef GUI_HPP
#define GUI_HPP 

#include <SFML/Graphics.hpp>
#include "TextureHolder.hpp"
#include <vector>
#include <iostream>
#include "State.hpp"
#include "game.hpp"

using namespace std;
using namespace sf;



class Gui{
public:
	Gui();
	void run();
private:
	void processEvents();
	void update();
	void render();
	void handlerPlayerInput(Vector2i v);
private:
	RenderWindow mWindow;
	TextureHolder textures;
	Sprite mTable[3][3];
	vector<Sprite> toDraw;
	bool isPlayer; 
	Font arial;
	char table[3][3] = {{'.','.','.'},{'.','.','.'},{'.','.','.'} };
	State ini;
	Text mPosition,mResult;





};



#endif