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
	v.first= -2000;
	v.second = make_pair(-2,-2);
	u.makeDescendents();
	
	while(!u.ls.empty()){
		
		v= max(v,minValue(u.ls.front()));
		assert(minValue(u.ls.front()).first != 1000);
			
		u.ls.pop_front();
	}
	return v;
}

movement game::minValue(State u){
	movement check;
	check.first=u.getUtility();
	
	if((check.first!=0 && check.first % 700 == 0 ) || u.moves ==4){
		cout<<"Deph: "<<u.moves<<endl;
		cout<<"Utility: "<<u.getUtility()<<endl;
		check.second.first = u.move.first;
		check.second.second = u.move.second;
		return check;
	}
	
	movement v;
	v.first= 2000;
	v.second = make_pair(-2,-2);
	u.makeDescendents();
	
	while(!u.ls.empty()){

		v = min(v,maxValue(u.ls.front()));

		
		
		u.ls.pop_front();
	}
	return v;
}


pair<int,int> game::alfa_beta(State ini){
	movement v= maxValueAB(ini,INT_MIN,INT_MAX);

	return v.second;

}

movement game::maxValueAB(State u,int alfa,int beta){
	movement check;
	check.first=u.getUtility();

	if((check.first!=0 && check.first % 700 == 0 ) || u.moves ==4){
		cout<<"Deph: "<<u.moves<<endl;
		cout<<"Utility: "<<u.getUtility()<<endl;
		check.second.first = u.move.first;
		check.second.second = u.move.second;
		return check;
			
	}
	

	movement v;
	v.first= INT_MIN;
	v.second = make_pair(-2,-2);
	u.makeDescendents();
	
	while(!u.ls.empty()){
		v= max(v,minValueAB(u.ls.front(),alfa,beta));
	
		u.ls.pop_front();

		if(v.first>= beta)
			return v;	
		
		alfa = max(v.first,alfa);
	}
	return v;
}

movement game::minValueAB(State u,int alfa,int beta){
	movement check;
	check.first=u.getUtility();

	if((check.first!=0 && check.first % 700 == 0 ) || u.moves ==4){
		cout<<"Deph: "<<u.moves<<endl;
		cout<<"Utility: "<<u.getUtility()<<endl;
		check.second.first = u.move.first;
		check.second.second = u.move.second;
		return check;
			
	}
	

	movement v;	 
	v.first= INT_MAX;
	v.second = make_pair(-2,-2);
	u.makeDescendents();
	
	while(!u.ls.empty()){
		
		v = min(v,maxValueAB(u.ls.front(),alfa,beta));
		
			
		u.ls.pop_front();

		if(v.first<= alfa)
			return v;
		beta = min(v.first,beta);
	}
	return v;
}


void game::ui(){
	
	char table[3][3] = {{'X','.','.'},{'O','X','.'},{'.','O','.'} };

	State ini(table,'X');
	char choice; 

	cout<<endl;
	cout<<"\tWhich player will play first?"<<endl;
	cout<<endl;
	cin>>choice;

	//cout<<"Utility: "<<ini.getUtility()<<endl;

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
