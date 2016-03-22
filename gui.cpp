#include "gui.hpp"



Gui::Gui():mWindow(VideoMode(640,480),"Tic Tac Toe IA-FCUP2015/16",Style::Close),isPlayer(false),ini(table,'X'),mPosition(),mResult()

{
	textures.load(Textures::Block,"square.png");
	textures.load(Textures::Cross,"cross.png");
	textures.load(Textures::Circle,"circle.png");
	arial.loadFromFile("arial.ttf");
	

	mPosition.setPosition(250.f,50.f);
	mPosition.setColor(Color::White);
	mPosition.setFont(arial);
	mPosition.setCharacterSize(18);
	mPosition.setString("15");

	mResult.setPosition(250.f,70.f);
	mResult.setColor(Color::White);
	mResult.setFont(arial);
	mResult.setCharacterSize(18);
	mResult.setString("Result: unfinished");

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			mTable[i][j].setTexture(textures.get(Textures::Block));
			mTable[i][j].setPosition(55.f*i,55.f*j);
		}
	}



}



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
			case Event::MouseButtonPressed :
				switch(event.key.code){
					case Mouse::Left:
						handlerPlayerInput(Mouse::getPosition(mWindow));
				}
				
				
		}
	}

}


void Gui::handlerPlayerInput(Vector2i v){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(mTable[i][j].getPosition().x<v.x && mTable[i][j].getPosition().x+50>v.x &&
			 mTable[i][j].getPosition().y<v.y && mTable[i][j].getPosition().y+50>v.y ){
			 	if(isPlayer && ini.table[i][j]=='.'){
			 		Sprite tmp;
			 		tmp.setTexture(textures.get(Textures::Circle));
			 		tmp.setPosition(55.f*i,55.f*j);
			 		toDraw.push_back(tmp);
			 		isPlayer=false;
			 		ini.table[i][j]='O';
				}
			}
		}
	}
	
	
}


void Gui::update(){

	if(ini.getUtility() % 700 != 0 || ini.getUtility()==0){
		if(!isPlayer){
			Sprite tmp;
			
			tmp.setTexture(textures.get(Textures::Cross));
			pair<int,int> tmp2 = game::alfa_beta(ini);
			tmp.setPosition(55.f*tmp2.first,55.f*tmp2.second);
			toDraw.push_back(tmp);
			ini.table[tmp2.first][tmp2.second] ='X';
			mPosition.setString("Computer move: "+ to_string(tmp2.first) + " " +to_string(tmp2.second) );
			isPlayer = true;
			

		}
	}
	else{
		if(ini.getUtility() == 1400)
			mResult.setString("Result: You Lose");
		else if(ini.getUtility() == 700)	
			mResult.setString("Result: You Tie");
		else if(ini.getUtility() == -700)
			mResult.setString("Result: You Win");	
		
		isPlayer = false;
		
	}

}

void Gui::render(){
	mWindow.clear();
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			mWindow.draw( mTable[i][j]);
	for(int i=0;i<toDraw.size();i++)
		mWindow.draw(toDraw[i]);
	mWindow.draw(mPosition);
	mWindow.draw(mResult);		
	mWindow.display();
}