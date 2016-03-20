#ifndef STATE_HPP
#define STATE_HPP


#include <list>
#include <iostream>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;


enum utility{ victory=700,tie=0,defeat=-700,unfinished='?'};




class State{

public:
	char table[3][3];
	list<State> ls;
	char player;
	int moves;
	pair<int,int> move;
	State* stateToMove;


	State(char table[3][3],int moves,char player,pair<int,int> move,State* stateToMove);
	State(char table[3][3],char player):State(table,0,player,make_pair(-1,-1),nullptr){};

	void makeDescendents();

	int getUtility();

	void print();

	int contWaystoWin(char c);

	int utilityNoFinished();





};


#endif