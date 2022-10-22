#include <iostream>
#include "trees/treeSO.hpp"
#include <cstring>

int main(int nargs, char** vargs){

	trees::TreeSO SO;
	std::cout<< "-- Bienvenido a TreeSO -- \n^^ Autores: Luis Corvalan y Macarena Ferrari ^^"<<std::endl;

	//♦♦♦♦hacer un while que no termine hasta que llaman a exit del SO

	std::cout<< SO.getRuta_dir()<< "#"<<std::endl;		//imprimir la ubicacion actual en el sistema de archivos
	SO.mkdir("Hola");
	SO.mkdir("Hola");
	SO.mkfile("Holaa",".");
	SO.mkdir("Holaab");
	SO.ls(".");

	SO.cd("Hola");
	SO.mkdir("a");
	SO.mkdir("Hola");
	SO.ls(".");

	SO.cd("..");
	SO.ls(".");
	
	SO.cd("/Hola/a");
	SO.mkfile("Holaa",".");
	SO.ls(".");
	//SO.find("..","Hola");
	//♦♦♦♦ver como hacerlo con los argv y argc para que se vaya interactuando con la terminal
	SO.tree();
	SO.exit();

	return 0;
}
