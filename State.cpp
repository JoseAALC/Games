#include "State.hpp"

State::State(char table[][3],int moves,char player,pair<int,int> move){
	this->moves = moves;
	this->player = player;
	this->move = move;

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
	char copy_table[3][3];
	copy(&table[0][0], &table[0][0]+3*3,&copy_table[0][0]);
	

	for(int i=0;i<3;i++){	
		for(int j=0;j<3;j++){
			if(copy_table[i][j]=='.'){
				if(moves ==0)
					tmp = make_pair(i,j);
				else
					tmp = this->move;

				copy_table[i][j] = player;
				char new_player = (player =='X') ? 'O':'X'; 
				ls.push_back(State(copy_table,this->moves+1,new_player,tmp));
				copy_table[i][j] ='.';
			}
		}
	}
}


int State::getUtility(){return 0;}


