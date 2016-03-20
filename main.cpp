#include "State.hpp"

int main(int argc, char const *argv[]){
	char c[3][3] = {{'.','.','.'},{'.','.','.'},{'.','.','.'} };

	State ini(c,'X');
	ini.makeDescendents();
	for(auto e : ini.ls){
		e.print();
	}

	return 0;
} 