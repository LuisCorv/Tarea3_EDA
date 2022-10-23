#include <iostream>
#include "trees/treeSO.hpp"
#include <cstring>

using namespace std;

int main(int nargs, char** vargs){

	trees::TreeSO SO;
	cout<< "-- Bienvenido a TreeSO -- \n^^ Autores: Luis Corvalan y Macarena Ferrari ^^"<<endl;
	cout<< SO.getRuta_dir()<< "#"<<endl;
	bool flag = false;
	string ins;
	string ruta = "";
	string comm = "";
	string nuevo;

	while(!flag){
		getline(cin, ins);
		if (ins.length() == 0){
			cout<<"El comando ingresado no es válido"<<endl;
			flag = true;
		}
		else {
			if (ins[0]== '/'){
				if (ins[1] != '#'){
					for (int i = 0; i < ins.length(); i++){
						if (ins[i] != '#'){
							ruta = ruta + ins[i];
						}
						if (ins[i] == '#'){
							ruta = ruta + '#';
							ins = ins.erase(0, i+2);
							break;
						}
						
					}
					cout<<"Ruta: "<<ruta<<endl;
					
				}

				
				else{
					ruta = "/#";
					ins = ins.erase(0,2);
				}
				
				//obtener instruccion
				for (int i=0; i < ins.length(); i++){
					if(ins[i] != ' '){
						comm = comm + ins[i];
					}
					else if (ins[i] == ' '){
						ins = ins.erase(0, i+1);
						break;
					}
				}
				cout << comm << endl;
				nuevo = ins;
				cout << nuevo << endl;
			}
		}
	}

	//♦♦♦♦hacer un while que no termine hasta que llaman a exit del SO

			//imprimir la ubicacion actual en el sistema de archivos
			/*
	SO.mkdir("A");
	SO.mkdir("B");
	SO.mkfile("c",".");
	SO.mkdir("D");
	SO.ls(".");

	SO.cd("A");
	SO.mkdir("a");
	SO.mkdir("A");
	SO.ls(".");

	SO.cd("..");
	SO.ls(".");
	
	SO.cd("/A/a");
	SO.mkfile("a_",".");
	SO.ls(".");
	SO.find("/A","a");
	//♦♦♦♦ver como hacerlo con los argv y argc para que se vaya interactuando con la terminal
	SO.tree();
	SO.exit();
*/
	return 0;
}
