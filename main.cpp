#include "game.hpp"
#include "gui.hpp"
int main(int argc, char const *argv[]){
	
	char table[3][3] = {{'.','.','.'},{'.','.','.'},{'.','.','.'} };

	State ini(table,'X');
	//ini.makeDescendents();

	/*for(auto e: ini.ls){
		cout<<game::minValueAB(e,INT_MIN,INT_MAX).first<<endl;
	}*/
	Gui game;
	game.run();
	//game::ui();

	//pair<int,int> w= game::minimax(ini);
	//cout<<w.first<<" "<<w.second<<endl;
	
	return 0;
} 