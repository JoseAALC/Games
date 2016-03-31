#include "game.hpp"

Movement max(Movement a,Movement b){
	if(a.moveValue < b.moveValue){
		delete (a.leaf);
		return b;
	}
	else if(a.moveValue > b.moveValue){
		delete (b.leaf);
		return a;
	}

	if	(a.getLeafDepth() > b.getLeafDepth()){
		delete (a.leaf);
		return b;
	}
	else {
		delete (b.leaf);
		return a;
	}
}

Movement min(Movement a,Movement b){

	if(a.moveValue > b.moveValue){
		delete (a.leaf);
		return b;
	}
	else if(a.moveValue < b.moveValue){
		delete (b.leaf);
		return a;
	}
	else if	(a.getLeafDepth() < b.getLeafDepth()){
		delete (a.leaf);
		return b;
	}
	else {
		delete (b.leaf);
		return a;
	}
}	

pair<int,int> game::minimax(State ini){
	Movement v = maxValue(ini);
	return v.move;	
}

Movement game::maxValue(State u){
	Movement check(u.getUtility(),u.move,&u);

	if((check.moveValue!=0 && check.moveValue % 700 == 0 ) || u.moves == 4){
		return check;		
	}
	
	Movement v(-2000);

	u.makeDescendents();
	
	while(!u.ls.empty()){
		
		v= max(v,minValue(u.ls.front()));
		//assert(minValue(u.ls.front()).moveValue != 1000);
			
		u.ls.pop_front();
	}
	return v;
}

Movement game::minValue(State u){
	Movement check(u.getUtility(),u.move,&u);
	
	if((check.moveValue!=0 && check.moveValue % 700 == 0 ) || u.moves ==4){	
		return check;
	}
	
	Movement v(2000);
	u.makeDescendents();
	
	while(!u.ls.empty()){

		v = min(v,maxValue(u.ls.front()));
		u.ls.pop_front();
	}
	return v;
}


pair<int,int> game::alfa_beta(State ini){
	Movement v= maxValueAB(ini,INT_MIN,INT_MAX);

	return v.move;

}

Movement game::maxValueAB(State u,int alfa,int beta){
	Movement check(u.getUtility(),u.move,&u);

	if((check.moveValue!=0 && check.moveValue % 700 == 0 ) || u.moves ==4){

		return check;
			
	}
	

	Movement v(INT_MIN);
	u.makeDescendents();
	
	while(!u.ls.empty()){
		v= max(v,minValueAB(u.ls.front(),alfa,beta));
		u.ls.pop_front();

		if(v.moveValue>= beta)
			return v;	
		
		alfa = max(v.moveValue,alfa);
	}
	return v;
}

Movement game::minValueAB(State u,int alfa,int beta){
	Movement check(u.getUtility(),u.move,&u);

	if((check.moveValue!=0 && check.moveValue % 700 == 0 ) || u.moves ==4){
		return check;
			
	}
	

	Movement v(INT_MAX);	 
	u.makeDescendents();
	
	while(!u.ls.empty()){
		
		v = min(v,maxValueAB(u.ls.front(),alfa,beta));
		
			
		u.ls.pop_front();

		if(v.moveValue<= alfa)
			return v;
		beta = min(v.moveValue,beta);
	}
	return v;
}


void game::ui(){
	
	char table[3][3] = {{'.','.','.'},{'.','.','.'},{'.','.','.'} };

	
	char choice; 
	char algorithm;
	cout<<endl;
	cout<<"\tWhich algorithm will be used?"<<endl;
	cin>>algorithm;
	cout<<"\tWhich player will play first?"<<endl;
	cout<<endl;
	cin>>choice;
	cout<<"\tWhich symbol will be computer?"<<endl;
	cin>>pc;
	char start;

	if(choice == 'P')
		start =pc;
	else
		start = (pc=='X') ? 'O':'X'; 

	State ini(table,start);

	while(ini.getUtility() % 700 != 0 || ini.getUtility()==0){


		pair<int ,int> tmp;
		switch(choice){

			case 'P' :
			if(algorithm=='m'){
				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				tmp = minimax(ini);
				high_resolution_clock::time_point t2 = high_resolution_clock::now();
				cout<<"Time elapsed: "<<duration_cast<microseconds>( t2 - t1 ).count()<<endl;
			}
			else{
				high_resolution_clock::time_point t1 = high_resolution_clock::now();
				tmp = alfa_beta(ini);
				high_resolution_clock::time_point t2 = high_resolution_clock::now();
				cout<<"Time elapsed: "<<duration_cast<microseconds>( t2 - t1 ).count()<<endl;
			}
			cout<<tmp.first<<" "<<tmp.second<<endl;
			break;

			case 'I':
			cout<<"\tInsert Position to play:"<<endl;
			cout<<endl;
			cin>>tmp.first>>tmp.second;
			if(tmp.first <0 || tmp.first>=3 || tmp.second < 0 || tmp.second >=3 || ini.table[tmp.first][tmp.second]!='.' ){
				cout<<"Invalid Position"<<endl;
				cout<<endl;
				continue;
			}
			break;
		}

		
		ini.table[tmp.first][tmp.second] = ini.player;

		ini.player = (ini.player =='X') ? 'O':'X';
		choice = (choice=='P') ? 'I':'P';
		ini.print();

	}

	if(ini.getUtility() == utility::victory){
		cout<<"You Lose the game!"<<endl;
	}
	if(ini.getUtility() == utility::defeat){
		cout<<"You are a cheater!"<<endl;
	}
	if(ini.getUtility() == utility::tie){
		cout<<"We are tie"<<endl;
	}
}
