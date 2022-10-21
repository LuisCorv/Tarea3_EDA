#include <iostream>
#include "trees/treeSO.hpp"
#include <cstring>

int main(int nargs, char** vargs){
	trees::TreeSO SO;
	SO.insert("a",1,"/");
	SO.insert("b",0,"a");
	SO.insert("c",1,"/");
	SO.insert("l",0,"c");
	SO.insert("h",1,"c");
	SO.insert("b",1,"c");
	SO.traverse();
	
	return 0;
}
