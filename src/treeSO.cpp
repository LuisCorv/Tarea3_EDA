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

bool check_name(std::string nom, TreeListNode* ptrt){
	bool ans=true;
	if (ptrt==nullptr){
		return ans;
	}
	
	Item* ptr = ptrt->getData();
	
	if (ptr!=nullptr){
		if (ptr->getName()==nom){
			ans= false;
			return ans;
		}
		else{
			ptrt = ptrt->getNext();
			if (ptrt==0){
				return ans;
			}
			ans=check_name(nom, ptrt);
		}
		
	}
	return ans;
	
}
//------------------------------------------------------------------------------------------------------
void TreeSO::mkdir(std::string nom){
	if (nom!="cd" and nom!="ls" and nom!="rm" and nom!="mkdir" and nom!="mkfile" and nom!="find" and nom!="exit" and nom!="tree"){
		
		bool ans = true;

		//validar que no exista la carpeta con ese nombre
		TreeList* childrenList = dir->getChildren();
		TreeListNode* ptr = childrenList->getHead();
		ans=check_name(nom,ptr);
		if (ans){ 
			Item* parent= dir;		//obtener el nodo padre es en este caso es dir
			if (parent != nullptr){
				Item* child= new trees::Item(nom,1);
				if(dir->getRuta()==root->getRuta()){
					child->setRuta(parent->getRuta()+nom);
				}
				else{
					child->setRuta(parent->getRuta()+"/"+nom);
				}
				parent->getChildren()->insertFirst(child);
				child->setParent(parent);
			}
		}
		else{
			std::cout<<"Ya existe una carpeta con nombre '"<<nom<<"' ingresada en el directorio: "<< dir->getName()<<std::endl;
		}
	}
	else{
		std::cout<< "Este nombre esta reservado, porfavor ingrese otro"<<std::endl;
	}
	
}

//------------------------------------------------------------------------------------------------------

void TreeSO::mkfile(std::string nom, std::string ruta){
	if ((nom!="cd" and nom!="ls" and nom!="rm" and nom!="mkdir" and nom!="mkfile" and nom!="find" and nom!="exit" and nom!="tree")){
		if (ruta!="cd" and ruta!="ls" and ruta!="rm" and ruta!="mkdir" and ruta!="mkfile" and ruta!="find" and ruta!="exit" and ruta!="tree"){
			Item* parent= nullptr;		
			bool ans = false;

			//validar si la ruta es valida (ver que exista la ruta entre las Ruta de cada Item, ademas de revisar que esta ruta no termine en un Tipo =0)
			if(ruta==".."){
				if(dir->getName()==root->getName()){
					std::cout<< "Comando invalido:  Usted desea ir al directorio padre de " << root->getName() <<"# , lo cual no es posible, ya que es la raiz del sistema de archivos "<<std::endl;
					return;
				}
				parent=dir->getParent();
				ans=true;
			}
			else if(ruta=="."){ 
				ans=true;
				parent=dir;
			}
			else{
				if(find_ruta(ruta)!=nullptr){
					parent=find_ruta(ruta);
					ans=true;
				}
				else{
					std::cout<<"La ruta '"<<ruta<<"' ingresada es invalida."<<std::endl;
					return;
				}
				
			}
			//metodo validar ruta
			if (parent==nullptr | parent->getType()==0){
					ans=false;
			}

			if (ans){ //arreglar este metodo
				bool ans1 = true;
				
				//validar que no exista la carpeta con ese nombre
				TreeList* childrenList = parent->getChildren();
				TreeListNode* ptr = childrenList->getHead();
				ans1=check_name(nom,ptr);

				if (ans1){	//si no existe en la carpeta
					if (parent != nullptr){
						Item* child= new trees::Item(nom,0);
						if(parent->getRuta()==root->getRuta()){  
							child->setRuta(parent->getRuta()+nom);
						}
						else{
							child->setRuta(parent->getRuta()+'/'+nom);
						}
						parent->getChildren()->insertFirst(child);
						child->setParent(parent);
					}
				}
				else{
				std::cout<<"Ya existe una carpeta con nombre '"<<nom<<"' ingresada en el directorio: "<< parent->getName()<<std::endl;
				}
				
			}
			else{
				std::cout<<"La ruta '"<<ruta<<"' ingresada es invalida.\n Esto puede ser debido a que se a ingresado el archivo '"<<parent->getName()<<"' como termino de la ruta y no una carpeta"<<std::endl;
			}
		}
		else{
		std::cout<< "Este nombre esta reservado, porfavor ingrese otro"<<std::endl;
		}
	}
	else{
		std::cout<< "Este nombre esta reservado, porfavor ingrese otro"<<std::endl;
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
		if(ptr==nullptr){
			std::cout<<std::endl;
			return;
		}
		ls_rec(ptr);
		std::cout<<std::endl;
	
	}
	else if (ruta==".."){
		if(dir->getName()==root->getName()){
			std::cout<< "Comando invalido:  Usted desea ir al directorio padre de " << root->getName() <<"# , lo cual no es posible, ya que es la raiz del sistema de archivos "<<std::endl;
			return;
		}
		Item * parent=dir->getParent();
		std::cout<<"# ";
		
		TreeList* childrenList = parent->getChildren();
		TreeListNode* ptr = childrenList->getHead();
		if(ptr==nullptr){
			std::cout<<std::endl;
			return;
		}
		ls_rec(ptr);
		
		std::cout<<std::endl;
		
	}
	else{
		Item* parent= nullptr;	
		bool ans = true;
		parent=find_ruta(ruta);	//metodo validar ruta
		if (parent==nullptr){
			ans=false;
		}
		else{
			if (parent->getType()==0){
			ans=false;
			}
		}
		if(ans){
			std::cout<< ruta <<"# \n# ";
			TreeList* childrenList = parent->getChildren();
			TreeListNode* ptr = childrenList->getHead();
			if(ptr==nullptr){
				std::cout<<std::endl;
				return;
			}
			ls_rec(ptr);
			std::cout<<std::endl;}
		else{
			std::cout<<"La ruta '"<<ruta<<"' ingresada es invalida."<<std::endl;
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
	if (ruta=="."){
		dir=dir;
	}
	else{
		Item* parent= nullptr;	
		bool ans = true;

		if (ruta[0]!='/'){
			TreeList*child=dir->getChildren();
			TreeListNode* ptr = child->getHead();
			while (ptr!=nullptr){
				Item* search= ptr->getData();
				if (search->getName()==ruta){
					ruta = search->getRuta();
				}
			}
		}
		parent=find_ruta(ruta);	//metodo validar ruta
		
		if (parent==nullptr){
			ans=false;
		}
		else {
			if(parent->getType()==0){
			ans=false;}
		}
		
		if (ans){
			dir=parent;			//actualizamos dir
		}
		else{
			std::cout<<"La ruta '"<<ruta<<"' ingresada es invalida."<<std::endl;
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
	//validar si el nombre es valido en dir
	TreeList* childrenList = dir->getChildren();
	TreeListNode* ptr = childrenList->getHead();
	ans=!check_name(nom,ptr);

	if(ans){
		Item* victim= find_in_file(nom,dir); //obtener el nodo victima = obtener el nodo al tenga nombre nom

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

void print_find(TreeList* lista){
	std::cout<<"# ";
	TreeListNode* ptr = lista->getHead();
	while (ptr!=nullptr ){
		std::cout<<ptr->getData()->getName()<<"  dir->("<< ptr->getData()->getRuta()<<") ";
		ptr = ptr->getNext();
	}
	std::cout<<std::endl;
}

TreeList* TreeSO::find_rec(std::string nom, Item* node, TreeList* lista){ 
	Item* ans = nullptr;
	if (node != nullptr){
		if (node->getName() == nom and node->getType()==0){
			ans=new Item(node->getName(),node->getType()); //copiamos los datos basicos del nodo, es decir nombre, tipo y su ruta
			ans->setRuta(node->getRuta());		//si posteriormente se quisiese saber su padre, buscamos en base a esa ruta
			lista->insertFirst(ans);
		}
		else if (node->getType()==1){ // search in children
			if (node->getName() == nom){
				ans=new Item(node->getName(),node->getType()); //copiamos los datos basicos del nodo, es decir nombre, tipo y su ruta
				ans->setRuta(node->getRuta());		//si posteriormente se quisiese saber su padre, buscamos en base a esa ruta
				lista->insertFirst(ans);
				TreeList* childrenList = node->getChildren();
				TreeListNode* ptr = childrenList->getHead();
				if (ptr==nullptr){
				return lista;}
				while (ptr!=nullptr){
					lista = find_rec(nom, ptr->getData(),lista);
					ptr = ptr->getNext();
				}	
			}
			else{
				TreeList* childrenList = node->getChildren();
				TreeListNode* ptr = childrenList->getHead();
				if (ptr==nullptr){
				return lista;}
				
				while (ptr!=nullptr && ans == nullptr){
					lista = find_rec(nom, ptr->getData(),lista);
					
					ptr = ptr->getNext();
				}
			}
		}
	}
	return lista;
}
TreeList* TreeSO::find(std::string ruta, std::string nom){//Arreglar para que nos de lo que piden
	Item* nodo = nullptr;
	TreeList list;
	TreeList* ans=& list;
	std::string nom_nodo;

	if(ruta==".."){
		if(dir->getName()==root->getName()){
			std::cout<< "Comando invalido:  Usted desea ir al directorio padre de " << root->getName() <<"# , lo cual no es posible, ya que es la raiz del sistema de archivos "<<std::endl;
			return ans;
		}
		nodo=dir->getParent();
	}
	else if(ruta=="."){
		nodo=dir;
	}
	else{
		if(find_ruta(ruta)!=nullptr){
			nodo=find_ruta(ruta);
		}
		else{
			std::cout<<"La ruta '"<<ruta<<"' ingresada es invalida."<<std::endl;
			 return ans;
		}
	}
	//metodo validar ruta
	if (nodo==nullptr | nodo->getType()==0){
		std::cout<<"La ruta '"<<ruta<<"' ingresada es invalida.\n Esto puede ser debido a que se a ingresado el archivo '"<<nodo->getName()<<"' como termino de la ruta y no una carpeta"<<std::endl;
		return ans;
	}
		

	
	

	//ver si es archivo o carpeta
	if (nodo->getType()==1){		//si es carpeta
			ans= find_rec(nom, nodo, &list);		//debe retornar una lista con todas las coincidencias encontradas.

			print_find(ans);	//Consideramos que es conveninete imprimir esta lista
			return ans;
	}
	else{		//si es archivo
		std::cout<<"La ruta '"<<ruta<<"' ingresada es invalida. \nDebido a que se a ingresado el archivo '"<<nom_nodo<<"' como termino de la ruta y no una carpeta"<<std::endl;
	}
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

void TreeSO::tree(std::string direccion){ //recibe una ruta		//♦♦♦♦Arreglar tree para que sea de un nodo dado y no desde raiz
	Item*nodo;
	bool ans=true;
	if(direccion==".."){
		if(dir->getName()==root->getName()){
			std::cout<< "Comando invalido:  Usted desea ir al directorio padre de " << root->getName() <<"# , lo cual no es posible, ya que es la raiz del sistema de archivos "<<std::endl;
			return;
		}
		nodo=dir->getParent();
	}
	else if(direccion=="."){
		nodo=dir;
	}
	else{
		if(find_ruta(direccion)!=nullptr){
			nodo=find_ruta(direccion);
		}
		else{
			std::cout<<"La ruta '"<<direccion<<"' ingresada es invalida."<<std::endl;
			 ans=false;
		}
		
	}
	if (ans){
		tree_rec(nodo, 1);
		std::cout<<"#" <<std::endl;
	}
	
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
//------------------------------------------------------------------------------------------------------
//Metodos auxiliares para obtener el nodo para una determinada ruta
Item* TreeSO::find_ruta_rec(std::string nom, Item* node){
	Item* ans = nullptr;
	if (node != nullptr){
		if (node->getRuta() == nom){
			ans = node;
			return ans;
		}
		else{ // search in children
			TreeList* childrenList = node->getChildren();
			TreeListNode* ptr = childrenList->getHead();
			while (ptr!=nullptr && ans == nullptr){
				ans = find_ruta_rec(nom, ptr->getData());
				ptr = ptr->getNext();
				
			}
		}
	}
	return ans;
}

Item* TreeSO::find_ruta(std::string nom){
	if (nom[0]!='/'){
		nom="/"+nom;
	}
	Item* ans = find_ruta_rec(nom, root);
	return ans;
}
//------------------------------------------------------------------------------------------------------
//Metodos auxiliares para obtener el nodo en una carpeta con un nombre especifico
Item* TreeSO::find_in_file_rec(std::string nom, TreeList* childrens){
	TreeListNode* ptr = childrens->getHead();
	while (ptr!=nullptr){
		Item* check= ptr->getData();
		if (check->getName()==nom){		//Si es archivo
			ptr = childrens->getHead();
			break;
		}
		else{
			ptr = ptr->getNext();
			
		}
	}
	return ptr->getData();
}
Item* TreeSO::find_in_file(std::string nom, Item * nodo){
	TreeList* childrenList = nodo->getChildren();
	Item* ans = find_in_file_rec(nom, childrenList);
	return ans;
}
//------------------------------------------------------------------------------------------------------

TreeSO::~TreeSO() {
	delete root;
}

} /* namespace trees */
