#include "game.hpp"



pair<int,int> game::minimax(State ini){
	int v = maxValue(ini);
	
	return make_pair(0,0);
}


int game::maxValue(State u){
	int check=u.getUtility();
	
	if(check != utility::unfinished)
		return check;
	
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
	
	if(check != utility::unfinished)
		return check;
	
	int v = INT_MAX;
	u.makeDescendents();
	
	while(!u.ls.empty()){
		v = min(v,maxValue(u.ls.front()));
		u.ls.pop_front();
	}
	return v;
}