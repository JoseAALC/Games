#include "gui.hpp"


Gui::Gui():mWindow(VideoMode(640,480),"Tic Tac Toe IA-FCUP2015/16",Style::Close)
{}



void Gui::run(){
	while(mWindow.isOpen()){
		processEvents();
		update();
		render();
	}
}


void Gui::processEvents(){
	Event event;
	while(mWindow.pollEvent(event)){
		switch(event.type){
			case Event::Closed:
				mWindow.close();
				break;
		}
	}

}


void Gui::handlerPlayerInput(){}


void Gui::update(){}

void Gui::render(){
	mWindow.clear();
	mWindow.display();
}