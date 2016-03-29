#ifndef STATE_HPP
#define STATE_HPP


#include <list>
#include <iostream>
#include <utility>
#include <algorithm>
#include <climits>
#include <cassert>
using namespace std;



enum utility{ victory=1400,tie=700,defeat=-700,unfinished='?'};


extern char pc;

class State{

public:
	char table[3][3];
	list<State> ls;
	char player;
	int moves;
	pair<int,int> move;

	
  	State(){}
	State(char table[3][3],int moves,char player,pair<int,int> move);
	State(char table[3][3],char player):State(table,0,player,make_pair(-1,-1)){};

	void makeDescendents();

	int getUtility();

	void print();

	int contWaystoWin(char c);

	int utilityNoFinished();





};


#endif