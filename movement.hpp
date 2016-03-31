#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include "State.hpp" 

class Movement{
public:
	Movement(int moveValue,pair<int,int> move,State* leaf);
	Movement(int moveValue);

	int getLeafUtility();
	int getLeafDepth();
	int moveValue;
	pair<int,int> move;
	State* leaf;

};


#endif