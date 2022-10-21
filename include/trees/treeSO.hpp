/*
 * tree.hpp
 *
 *  Created on: Aug 31, 2022
 *      Author: jsaavedr
 */

#ifndef TREE_HPP_
#define TREE_HPP_

#include "trees/Item.hpp"


namespace trees {

class TreeSO {
private:	
	Item* root; //Es la raiz del sistema de archivos
	Item * dir;	//Es la ubicacion actual en el sistema de archivos
	std::string rut_dir;		//Es la ruta hasta dir
public:
	TreeSO();
	void insert(Item* node,Item* parent);
	void insert(std::string nom, int val_child , std::string nom_parent);

	void mkdir(std::string nom);						//♦♦♦♦Funcion para crear carpetas o directorios
	void mkfile(std::string nom, std::string ruta);		//♦♦♦♦funcion para crear archivos
	
	void ls_rec(TreeListNode* ptr);
	void ls(std::string ruta);		//♦♦♦♦funcion para mostrar lo que se encuentra en esa carpeta 

	void cd(std::string ruta); 		//♦♦♦♦Funcion para movernos de carpeta 

	void rm_rec(std::string nom, TreeList * nodo);
	void rm(std::string nom);		//♦♦♦♦Funcion para eliminar 1 archivo o 1 carpeta (y los archivos que contiene) en la ubicacion actual

	Item* find_rec(std::string nom, Item* node);		//♦♦♦♦♦♦ Arreglar este find para que cumpla lo que nos piden
	Item* find(std::string nom);				//♦♦♦♦♦♦ Arreglar este find para que cumpla lo que nos piden

	void tree_rec(Item* node, int level);	//funcion para imprimir en formato de arbol
	void tree();

	void exit();	//Funcion para salir del sistema de archivos

	std::string getRuta_dir();
	virtual ~TreeSO();
};

} /* namespace trees */

#endif /* TREE_HPP_ */
