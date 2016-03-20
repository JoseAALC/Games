#ifndef GAME_HPP
#define GAME_HPP
#include "State.hpp"

namespace game{
	pair<int,int> minimax(State ini);

	int maxValue(State u);

	int minValue(State u);
}


#endif