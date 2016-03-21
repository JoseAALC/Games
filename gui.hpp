#ifndef GUI_HPP
#define GUI_HPP 

#include <SFML/Graphics.hpp>


using namespace sf;



class Gui{
public:
	Gui();
	void run();
private:
	void processEvents();
	void update();
	void render();
	void handlerPlayerInput();
private:
	RenderWindow mWindow;
	



};



#endif