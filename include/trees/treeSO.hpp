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
public:
	TreeSO();

	void mkdir(std::string nom);						//Funcion para crear carpetas o directorios
	void mkfile(std::string nom, std::string ruta);		//Funcion para crear archivos
	
	void ls_rec( TreeListNode* ptrt);
	void ls(std::string ruta);		//Funcion para mostrar lo que se encuentra en esa carpeta 

	void cd(std::string ruta); 		//Funcion para movernos de carpeta 

	void rm_rec(std::string nom, TreeList * nodo);
	void rm(std::string nom);		//Funcion para eliminar 1 archivo o 1 carpeta (y los archivos que contiene) en la ubicacion actual

	TreeList* find_rec(std::string nom, Item* node, TreeList* lista);		//Arreglar este find para que cumpla lo que nos piden
	TreeList* find(std::string ruta, std::string nom);				//Funcion para obtener una 'lista de nodos'


	void tree_rec(Item* node, int level);	//Funcion para imprimir en formato de arbol
	void tree();

	void exit();	//Funcion para salir del sistema de archivos

	std::string getRuta_dir();

	Item* find_ruta_rec(std::string nom, Item* node);		//Metodo recursivo que nos permite encontrar un Item dada una ruta
	Item* find_ruta(std::string nom);				//Metodo auxiliar para encontrar un Item dada una ruta4

	Item* find_in_file_rec(std::string nom, TreeList* childrens);		//Metodo recursivo que nos permite encontrar un Item dada un nombre dentro de un objeto en dir
	Item* find_in_file(std::string nom, Item * nodo);				//Metodo auxiliar para encontrar un Item dada un nombre dentro de un objeto en dir

	virtual ~TreeSO();
};

} /* namespace trees */

#endif /* TREE_HPP_ */
