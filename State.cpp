#include "State.hpp"


char pc ='X';


State::State(char table[][3],int moves,char player,pair<int,int> move,State* stateToMove){
	this->moves = moves;
	this->player = player;
	this->move = move;
	this->stateToMove = stateToMove;

	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			this->table[i][j]=table[i][j];
}


void State::print(){
	cout<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout<<this->table[i][j];
		cout<<endl;
	}
	cout<<endl;   

}

void State::makeDescendents(){
	pair<int,int> tmp;
	State* tmp2;
	char copy_table[3][3];
	copy(&table[0][0], &table[0][0]+3*3,&copy_table[0][0]);


	for(int i=0;i<3;i++){	
		for(int j=0;j<3;j++){
			if(copy_table[i][j]=='.'){
				if(moves ==0){
					tmp = make_pair(i,j);
					tmp2 = this;
				}
				else{
					tmp = this->move;
					tmp2 = this->stateToMove;
				}
				copy_table[i][j] = player;
				char new_player = (player =='X') ? 'O':'X'; 
				ls.push_back(State(copy_table,this->moves+1,new_player,tmp,tmp2));
				copy_table[i][j] ='.';
			}
		}
	}
}


int State::getUtility(){


	for(int i=0;i<3;i++){
		char here = table[i][i];
		if(table[i][0]==table[i][1] && table[i][1]==table[i][2] && table[i][0]!='.')
			if(pc == here)
				return utility::victory;
			else
				return utility::defeat;

			if(table[0][i]==table[1][i] && table[1][i]==table[2][i] && table[0][i]!='.')
				if(pc == here)
					return utility::victory;
				else
					return utility::defeat;


			}

			if(table[0][0]==table[1][1] && table[1][1]==table[2][2] && table[0][0]!='.'){
				char here = table[0][0];
				if(pc == here)
					return utility::victory;
				else
					return utility::defeat;
			}

			if(table[0][2]==table[1][1] && table[1][1]==table[2][0] && table[1][1]!='.'){
				char here = table[1][1];
				if(pc == here)
					return utility::victory;
				else
					return utility::defeat;
			}

			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(table[i][j] == '.')
						return utility::unfinished;
					return utility::tie;		




				}

int State::contWaystoWin(char c){
	int ways=0;
	char opponet = (c=='O') ? 'X':'O';


	for(int i=0;i<3;i++){
		bool isWay=true;
		for(int j=0;j<3;j++)
			if(table[i][j]==opponet)
				isWay=false;
		ways+=isWay;
		
	}
	
	for(int j=0;j<3;j++){
		bool isWay=true;
			for(int i=0;i<3;i++)
			if(table[i][j]==opponet)
				isWay=false;
		ways+=isWay;
	}

	bool isWay=true;
	for(int i=0;i<3;i++){
		
		if(table[i][i]==opponet)
			isWay = false;
		
	}
	ways+=isWay;

	int k=2;

	for(int i=0;i<3;i++){
		isWay=true;
		if(table[i][k-i]==opponet)
			isWay = false;
		
	}	
	ways+=isWay;
	return ways;
}

int State::utilityNoFinished(){
	char opponet = (player=='O') ? 'X':'O';
	return contWaystoWin(player) - contWaystoWin(opponet);
}
