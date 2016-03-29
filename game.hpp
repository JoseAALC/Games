#ifndef GAME_HPP
#define GAME_HPP

#include "movement.hpp"
#include <chrono>

using namespace std::chrono;

Movement max(Movement a,Movement b);

Movement min(Movement a,Movement b);


namespace game{
	
	void ui();

	pair<int,int> minimax(State ini);

	Movement maxValue(State u);

	Movement minValue(State u);

	pair<int,int> alfa_beta(State ini);
	
	Movement  maxValueAB(State u,int alfa,int beta);

	Movement  minValueAB(State u,int alfa,int beta);

}


#endif