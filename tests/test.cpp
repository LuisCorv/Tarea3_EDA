#include <iostream>
#include "trees/treeSO.hpp"
#include <cstring>

using namespace std;

int main(int nargs, char** vargs){

	trees::TreeSO SO;
	cout<< "-- Bienvenido a TreeSO -- \n^^ Autores: Luis Corvalan y Macarena Ferrari ^^"<<endl;
	cout<< SO.getRuta_dir()<< "#"<<endl;
	string inicio;
	string ruta = "/#";
	string inst = "";
	string car_arch = "";
	string extra = "";
	bool flag = false;

	while(!flag){
		
		ruta=SO.getRuta_dir()+"# ";
		cout << ruta << " ";
		getline(cin, inicio);

		if (inicio.length() == 0){
			cout<<"El comando ingresado no es válido"<<endl;
			flag = true;
		}
		else {
			
			
			//obtener instruccion
			inst = "";
			for (int i=0; i < inicio.length(); i++){
				if(inicio[i] != ' '){
					inst = inst + inicio[i];
				}

				else if (inicio[i] == ' '){
					inicio = inicio.erase(0, i+1);
					break;
				}
			}

			car_arch = "";
			extra = "";
			if (inst != "exit" ){
				for (int j = 0; j < inicio.length(); j++){
					if (inicio[j] != ' '){
						car_arch = car_arch + inicio[j];
					}

					else if (inicio[j] == ' '){
						inicio = inicio.erase(0, j+1);
						extra = inicio;
						break;
					}

				}
			}
			
			//distintas instrucciones
			
			if (inst == "exit" & car_arch == "exit"){// si no recibe parametro
				SO.exit();
				flag = true;

			}
			
			else if ((inst == "cd" | inst == "ls" | inst == "mkdir" | inst == "rm"| inst=="tree") & extra == ""){	//Si recien solo 1 parametro
				
				
				if (inst == "cd"){	
					bool ans = true;
					if(car_arch==inst ){
							cout << "Comando inválido, intente de nuevo" << endl;
						}
					else{
						if (ruta == "/# "){																			
						if (car_arch != ".."){
							ruta = "/" + car_arch ;
							
						}
						else{
							cout << "Comando invalido, ya esta en la raiz del arbol" << endl;
							ans = false;
						}
					}	
					else {
						
						if (car_arch == ".."){
							
							for (int j = ruta.length()-1; j > 0; j-- ){
								
								if (ruta[j] == '/'){
									ruta.pop_back();
									
									break;
								}
								ruta.pop_back();
							}

							
							
						}
						
						else {				
							ruta = ruta.erase(ruta.length()-2, 2);
							ruta = ruta + "/" + car_arch ;

						}
						
					}
					
					
					if (ans){
						SO.cd(ruta);
					}
					}
					
					

					
				}

				else if (inst == "tree"){//Modificar esto, ya que tree deberia recibir una ruta del nodo
					if(car_arch==inst ){
							cout << "Comando inválido, intente de nuevo" << endl;
						}
					else{
						SO.tree(car_arch);
					}
				}

				else if (inst == "ls"){ 
					if(car_arch==inst ){
							cout << "Comando inválido, intente de nuevo" << endl;
						}
					else{
						SO.ls(car_arch);
					}
					
				}

				else if (inst == "mkdir"){
					SO.mkdir(car_arch);
				}

				else if (inst == "rm"){
					SO.rm(car_arch);
				}

			}

			else if ((inst == "mkfile" | inst == "find") & extra != ""){
				

				if (inst == "mkfile"){ //arreglar para que verifique bien al darle la cantidad correcta o mayor de datos
					SO.mkfile(car_arch, extra);
				}
				

				else if (inst == "find"){//arreglar para que verifique bien al darle la cantidad correcta o mayor de datos
					SO.find(extra, car_arch);
				}

				
			}

			else {
				cout << "Comando inválido, intente de nuevo" << endl;
			}
		}
	}

	return 0;
}
