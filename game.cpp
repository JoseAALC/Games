#include "game.hpp"

movement max(movement a,movement b){
	if(a.first < b.first)
		return b;
	else 
		return a;
}

movement min(movement a,movement b){
	if(a.first > b.first)
		return b;
	else 
		return a;
}

pair<int,int> game::minimax(State ini){
	movement v = maxValue(ini);

	cout<<v.first<<endl;
	return v.second;
}

movement game::maxValue(State u){
	movement check;
	check.first=u.getUtility();

	if((check.first!=0 && check.first % 700 == 0 ) || u.moves ==4){
		
		check.second.first = u.move.first;
		check.second.second = u.move.second;
		return check;
			
	}
	

	movement v;
	v.first= -1000;
	v.second = make_pair(-2,-2);
	u.makeDescendents();
	
	while(!u.ls.empty()){
		
		v= max(v,minValue(u.ls.front()));
			
		u.ls.pop_front();
	}
	return v;
}

movement game::minValue(State u){
	movement check;
	check.first=u.getUtility();
	
	if((check.first!=0 && check.first % 700 == 0 ) || u.moves ==4){
		
		check.second.first = u.move.first;
		check.second.second = u.move.second;
		return check;
	}
	
	movement v;
	v.first= 1000;
	v.second = make_pair(-2,-2);
	u.makeDescendents();
	
	while(!u.ls.empty()){

		v = min(v,maxValue(u.ls.front()));

		
		
		u.ls.pop_front();
	}
	return v;
}

/*

pair<int,int> game::alfa_beta(State ini){
	int v=(maxValueAB(ini,INT_MIN,INT_MAX));

	return winner;

}

int game::maxValueAB(State u,int alfa,int beta){
	int check=u.getUtility();
	if(check!=utility::unfinished)
			return check;
	int v = INT_MIN;
	
	u.makeDescendents();
	
	while(!u.ls.empty()){
		v = max(v,minValueAB(u.ls.front(),alfa,beta));
		u.ls.pop_front();
		if(v>= beta)
			return v;
		alfa = max(v,alfa);
	}
	return v;	

}

int game::minValueAB(State u,int alfa,int beta){
	int check=u.getUtility();
	if(check!=utility::unfinished)
			return check;
	int v = INT_MAX;
	
	u.makeDescendents();
	
	while(!u.ls.empty()){
		v = max(v,minValueAB(u.ls.front(),alfa,beta));
		u.ls.pop_front();
		if(v>= alfa)
			return v;
		beta = min(v,beta);
	}
	return v;	

}

*/


void game::ui(){
	char table[3][3] = {{'.','.','.'},{'.','.','.'},{'.','.','.'} };

	State ini(table,'X');
	
	char choice; 

	cout<<endl;
	cout<<"\tWhich player will play first?"<<endl;
	cout<<endl;
	cin>>choice;

	cout<<"Utility: "<<ini.getUtility()<<endl;

	while(ini.getUtility() % 700 != 0 || ini.getUtility()==0){

		pair<int ,int> tmp;
		switch(choice){

			case 'P' :
			tmp = minimax(ini);
			cout<<tmp.first<<" "<<tmp.second<<endl;
			break;

			case 'I':
			cin>>tmp.first>>tmp.second;
			break;
		}

		
		ini.table[tmp.first][tmp.second] = ini.player;

		ini.player = (ini.player =='X') ? 'O':'X';
		choice = (choice=='P') ? 'I':'P';
		ini.print();

	}
}
