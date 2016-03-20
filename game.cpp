#include "game.hpp"
pair<int,int> winner;
int m= INT_MAX;

pair<int,int> game::minimax(State ini){
	int v = maxValue(ini);
	
	cout<<v<<endl;
	return winner;
}


int game::maxValue(State u){
	int check=u.getUtility();
	
	if(check %700 ==0){
		
		if(u.moves<m){
			winner = u.move;
			m=u.moves;
	}
		return check;
	}
	
	int v = INT_MIN;
	u.makeDescendents();
	
	while(!u.ls.empty()){
		v = max(v,minValue(u.ls.front()));
		u.ls.pop_front();
	}
	return v;
}

int game::minValue(State u){
	int check=u.getUtility();
	
	if(check %700 ==0)
		return check;
	
	int v = INT_MAX;
	u.makeDescendents();
	
	while(!u.ls.empty()){
		v = min(v,maxValue(u.ls.front()));
		u.ls.pop_front();
	}
	return v;
}