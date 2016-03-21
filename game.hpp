#ifndef GAME_HPP
#define GAME_HPP

#include "State.hpp"

typedef pair<int,pair<int,int>> movement;


movement max(movement a,movement b);

movement min(movement a,movement b);


namespace game{
	
	void ui();

	pair<int,int> minimax(State ini);

	movement maxValue(State u);

	movement minValue(State u);

	pair<int,int> alfa_beta(State ini);

	int maxValueAB(State u,int alpha,int beta);

	int minValueAB(State u,int alpha,int beta);
}


#endif