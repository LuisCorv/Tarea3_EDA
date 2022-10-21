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
	dir=root;
	rut_dir="/";
}
/*
void TreeSO::insert(Item* child, Item* parent){
	if (parent != nullptr){
		parent->getChildren()->insertFirst(child);
	}
}
*/

//------------------------------------------------------------------------------------------------------
void TreeSO::mkdir(std::string nom){

	//♦♦♦♦validar si la ruta es valida

		//si lo es
			//obtener el nodo padre (el ultimo de la ruta)
			Item* parent= nullptr;		//♦♦♦♦♦♦modificar
			if (parent != nullptr){
				Item* child= new trees::Item(nom,1);
				parent->getChildren()->insertFirst(child);
			}
}

//------------------------------------------------------------------------------------------------------
void TreeSO::mkfile(std::string nom, std::string ruta){
	//♦♦♦♦validar si la ruta es valida

		//si lo es
			//obtener el nodo padre (el ultimo de la ruta)
			Item* parent= nullptr;		//♦♦♦♦♦♦modificar
			if (parent != nullptr){
				Item* child= new trees::Item(nom,0);
				parent->getChildren()->insertFirst(child);
			}
		
}

//------------------------------------------------------------------------------------------------------
void TreeSO:: ls_rec(TreeListNode* ptr){
	while (ptr!=nullptr){
		std::cout<<ptr->getData()->getName()<< " ";
		ptr = ptr->getNext();
		ls_rec(ptr);
	}
	
}	 	
void TreeSO::ls(std::string ruta){
	if (ruta=="."){
		if (dir != nullptr){
			std::cout<< rut_dir <<"# "<<std::endl;
			TreeList* childrenList = dir->getChildren();
			TreeListNode* ptr = childrenList->getHead();
			ls_rec(ptr);
			std::cout<<std::endl;
		}
	}
	else{
		//♦♦♦♦validar si la ruta es valida

		//si lo es
			//obtener el nodo padre (el ultimo de la ruta)
			Item* parent= nullptr;		//♦♦♦♦♦♦modificar
			std::cout<< ruta <<"# "<<std::endl;
			TreeList* childrenList = parent->getChildren();
			TreeListNode* ptr = childrenList->getHead();
			ls_rec(ptr);
			std::cout<<std::endl;

	}
}
//------------------------------------------------------------------------------------------------------
void TreeSO::cd(std::string ruta){
	if (ruta==".."){
		dir=dir->getParent();
		//♦♦♦♦actualizar rut_dir
	}
	else{
		//♦♦♦♦validar si la ruta es valida

		//si lo es
			//obtener el nodo padre (el ultimo de la ruta)
			Item* parent= nullptr;		//♦♦♦♦♦♦modificar

			dir=parent;			//actualizamos dir
			rut_dir=ruta;		//actualizamos rut_dir
			
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
	//♦♦♦♦validar si la nombre es valido en dir

	//si lo es
		Item* victim= nullptr;		//♦♦♦♦♦♦modificar
		if (victim->getType()==0){		//Si es archivo
			dir->getChildren()->remove(nom);
		}
		else{		//Si es carpeta
			TreeList* childrenList = victim->getChildren();
			rm_rec(nom,childrenList);
			dir->getChildren()->remove(nom);
		}
			

}



//------------------------------------------------------------------------------------------------------
/*
void TreeSO::insert(std::string nom, int val_child, std::string nom_parent){
	Item* parent = find(nom_parent);
	if (parent != nullptr){
		Item* child = new Item(nom,val_child);
		insert(child, parent);
		std::cout << "insertado " << nom << " in " << nom_parent << " at " << parent << std::endl;
	}
}*/
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
	return rut_dir;
}

TreeSO::~TreeSO() {
	delete root;
}

} /* namespace trees */
