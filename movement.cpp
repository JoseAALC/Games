#include "movement.hpp"

Movement::Movement(int moveValue,pair<int,int> move,State* leaf){
	this->moveValue =moveValue;
	this->move = move;
	this->leaf =new State(leaf->table,leaf->moves,leaf->player,leaf->move);
}

Movement::Movement(int moveValue){
	this->moveValue =moveValue;
	this->move = make_pair(-2,-2);
	this->leaf = nullptr;
}

int Movement::getLeafUtility(){ return leaf->getUtility(); }

int Movement::getLeafDepth(){ return leaf->moves; }