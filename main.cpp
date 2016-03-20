#include "game.hpp"

int main(int argc, char const *argv[]){
	char c[3][3] = {{'X','X','.'},{'O','.','.'},{'.','.','O'} };

	State ini(c,'X');

	pair<int,int> w= game::minimax(ini);
	cout<<w.first<<" "<<w.second<<endl;
	
	return 0;
} 