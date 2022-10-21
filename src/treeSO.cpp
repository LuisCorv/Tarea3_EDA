/*
 * tree.cpp
 *
 *  Created on: Aug 31, 2022
 *      Author: jsaavedr
 */

#include "trees/treeSO.hpp"
#include <iostream>

namespace trees {

TreeSO::TreeSO(){
	Item* node= new trees::Item("/",1);
	root = node;
	root->setRuta("/");
	dir=root;
	dir->setRuta("/");
}

std::string get_name(std:: string  nombre_de_donde_obtener){
	int size_obtener= nombre_de_donde_obtener.length();
	int size_eliminar=0;
	std::string extra;
	std::string copia=nombre_de_donde_obtener;
	int i=0;
	while (i<size_obtener){
		if (copia[size_obtener-i]=='/'){
			size_eliminar=size_obtener-i;
			break;
		}
		i++;
	}
	if(size_eliminar==0){
		extra=copia;
	}
	else{
		extra=copia.erase(size_eliminar);
	}
	return extra;
}
//------------------------------------------------------------------------------------------------------
void TreeSO::mkdir(std::string nom){
	bool ans = true;
	//♦♦♦♦validar que no exista la carpeta con ese nombre

	if (ans){ 
		Item* parent= dir;		//obtener el nodo padre es en este caso es dir
		if (parent != nullptr){
			Item* child= new trees::Item(nom,1);
			child->setRuta(parent->getRuta()+nom);
			parent->getChildren()->insertFirst(child);
		}
	}
	else{
		std::cout<<"Ya existe una carpeta con nombre "<<nom<<" ingresada en el directorio: "<< dir->getName()<<std::endl;
	}
	
}

//------------------------------------------------------------------------------------------------------
void TreeSO::mkfile(std::string nom, std::string ruta){
	Item* parent= nullptr;		
	bool ans = true;
	//♦♦♦♦validar si la ruta es valida (ver que exista la ruta entre las Ruta de cada Item, ademas de revisar que esta ruta no termine en un Tipo =0)
	if(ruta=="."){ 
		ans=true;
		parent=dir;
	}
	else{
		//si no existe ruta, entonces false
		
	}
	if (ans){ 
		bool ans1 = true;
		//♦♦♦♦validar que no exista la carpeta con ese nombre

		if (ans1){
			std::string nom_parent= get_name(ruta);	//obtener el nodo padre (el ultimo de la ruta)
			Item* parent= find(nom_parent);	
			if (parent != nullptr){
				Item* child= new trees::Item(nom,0);
				child->setRuta(parent->getRuta()+nom);
				parent->getChildren()->insertFirst(child);
			}
		}
		else{
		std::cout<<"Ya existe una carpeta con nombre "<<nom<<" ingresada en el directorio: "<< dir->getName()<<std::endl;
		}
		
	}
	else{
		std::cout<<"La ruta "<<ruta<<" ingresada es invalida."<<std::endl;
	}
}

//------------------------------------------------------------------------------------------------------
void TreeSO:: ls_rec(TreeListNode* ptrt){
	Item* ptr = ptrt->getData();
	if (ptr!=nullptr){
		std::cout<< ptr->getName()<<" ";
		ptrt = ptrt->getNext();
		if (ptrt==0){
			return;
		}
		ls_rec(ptrt);
	}
	
}	 	
void TreeSO::ls(std::string ruta){
	if (ruta=="."){
		std::cout<<"# ";
		TreeList* childrenList = dir->getChildren();
		TreeListNode* ptr = childrenList->getHead();
		ls_rec(ptr);
		std::cout<<std::endl;
	
	}
	else{
		bool ans = true;
		//♦♦♦♦validar si la ruta es valida

		if(ans){
			std::string nom_parent= get_name(ruta);	//obtener el nodo padre (el ultimo de la ruta)
			Item* parent= find(nom_parent);	
			std::cout<< ruta <<"# "<<std::endl;
			TreeList* childrenList = parent->getChildren();
			TreeListNode* ptr = childrenList->getHead();
			ls_rec(ptr);
			std::cout<<std::endl;}
		else{
			std::cout<<"La ruta "<<ruta<<" ingresada es invalida."<<std::endl;
		}

	}
}
//------------------------------------------------------------------------------------------------------
void TreeSO::cd(std::string ruta){
	if (ruta==".."){
		if(dir->getName()==root->getName()){
			std::cout<< "Comando invalido:  Usted desea ir al directorio padre de " << root->getName() <<"# , lo cual no es posible, ya que es la raiz del sistema de archivos "<<std::endl;
			return;
		}
		dir=dir->getParent();
		
	}
	else{
		
		bool ans = true;
		//♦♦♦♦validar si la ruta es valida
		

		if (ans){
			std::string nom_parent= get_name(ruta);	//obtener el nodo padre (el ultimo de la ruta)
			Item* parent= find(nom_parent);	
			dir=parent;			//actualizamos dir
		}
		else{
			std::cout<<"La ruta "<<ruta<<" ingresada es invalida."<<std::endl;
		}
			
	}
}
//------------------------------------------------------------------------------------------------------
void TreeSO::rm_rec(std::string nom, TreeList* childrens){
	TreeListNode* ptr = childrens->getHead();
	while (ptr!=nullptr){
		Item* victim= ptr->getData();
		if (victim->getType()==0){		//Si es archivo
			childrens->removeFirst();
			ptr = childrens->getHead();
		}
		else{
			
			TreeList* childrenList = victim->getChildren();
			rm_rec(nom,childrenList);
			childrens->removeFirst();
			ptr = childrens->getHead();
			
		}
	}
}

void TreeSO:: rm(std::string nom){
	bool ans = true;
	//♦♦♦♦validar si la nombre es valido en dir

	if(ans){
		std::string nom_vic= get_name(nom);	//obtener el nodo victima (el ultimo de la 'ruta')
		Item* victim= find(nom_vic);

		if (victim->getType()==0){		//Si es archivo
			dir->getChildren()->remove(nom);
		}
		else{		//Si es carpeta
			TreeList* childrenList = victim->getChildren();
			rm_rec(nom,childrenList);
			dir->getChildren()->remove(nom);
		}
	}
	else{
			std::cout<<"El archivo/carpeta "<< nom<<" ingresado/ingresada para eliminar es invalido/invalida."<<std::endl;
		}


}

//------------------------------------------------------------------------------------------------------

Item* TreeSO::find_rec(std::string nom, Item* node){
	Item* ans = nullptr;
	if (node != nullptr){
		if (node->getName() == nom){
			ans = node;
		}
		else{ // search in children
			TreeList* childrenList = node->getChildren();
			TreeListNode* ptr = childrenList->getHead();
			while (ptr!=nullptr && ans == nullptr){
				ans = find_rec(nom, ptr->getData());
				ptr = ptr->getNext();
			}
		}
	}
	return ans;
}

Item* TreeSO::find(std::string nom){
	Item* ans = find_rec(nom, root);
	return ans;
}

//------------------------------------------------------------------------------------------------------
void TreeSO::tree_rec(Item* node, int level){
	if (node != nullptr){
		std::cout << std::string(level*2, '-');
		std::cout<<node->getName() <<std::endl;
		TreeList* childrenList = node->getChildren();
		TreeListNode* ptr = childrenList->getHead();
		while (ptr!=nullptr){
			tree_rec(ptr->getData(), level + 1);
			ptr = ptr->getNext();
		}
	}
}

void TreeSO::tree(){
	tree_rec(root, 1);
	std::cout<<"#" <<std::endl;
}
//------------------------------------------------------------------------------------------------------
void TreeSO::exit(){
	std::cout<< "Saliendo del sistema de archivos ... \nSe a logrado salir con exito."<< std::endl;
	std::exit(1);

}
//------------------------------------------------------------------------------------------------------
std::string TreeSO::getRuta_dir(){
	return dir->getRuta();
}

TreeSO::~TreeSO() {
	delete root;
}

} /* namespace trees */
