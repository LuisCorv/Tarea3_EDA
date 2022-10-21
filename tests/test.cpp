#include <iostream>
#include "trees/treeSO.hpp"
#include <cstring>

int main(int nargs, char** vargs){

	trees::TreeSO SO;
	std::cout<< "♪ Bienvenido a TreeSO ♪ \n ♣ Autores: Luis Corvalán y Macarena Ferrari ♣"<<std::endl;
	//♦♦♦♦hacer un while que no termine hasta que llaman a exit del SO
	std::cout<< SO.getRuta_dir()<< "#"<<std::endl;		//imprimir la ubicacion actual en el sistema de archivos
	
	//♦♦♦♦ver como hacerlo con los argv y argc para que se vaya interactuando con la terminal
	SO.insert("a",1,"/");
	SO.insert("b",0,"a");
	SO.insert("c",1,"/");
	SO.insert("l",0,"c");
	SO.insert("h",1,"c");
	SO.insert("b",1,"c");
	SO.tree();
	SO.exit();
	return 0;
}
