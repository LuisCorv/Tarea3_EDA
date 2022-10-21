/*
 * treeNode.cpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */

#include "trees/Item.hpp"
#include <iostream>

namespace trees {

Item::Item(std::string nom, int val): parent(nullptr), nombre(nom), children(new TreeList()) {
	if (val >1){
		std::cout<< "El valor asignado para crear la carpeta/archivo es "<<val<<" , por lo que es invalido.\n Si desea una carpeta asigne 1 a val, y si es un archivo 0. "<< std::endl;
		exit(1);	
	}
	tipo=val;
}

void Item::setParent(Item* node){
	parent = node;
}

void Item::setChildren(TreeList* list){
	children = list;
}
Item* Item::getParent(){
	return parent;
}
std::string Item::getName(){
	return nombre;
}
int Item::getType(){
	return tipo;
}
TreeList* Item::getChildren(){
	return children;
}

Item::~Item() {
	//action when a treeNode is deleted
	//delete the descendants only
	if (children != nullptr){
		delete children;
	}
}

} /* namespace trees */
