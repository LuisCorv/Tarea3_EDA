/*
 * treeNode.hpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */

#ifndef TREENODE_HPP_
#define TREENODE_HPP_

#include "trees/treeList.hpp"
#include <iostream>

namespace trees {

class TreeList;
class Item {
private:
	Item* parent;
	std::string nombre;	//name of the object
	int tipo; 	//type of the object
	TreeList* children;
public:
	Item(std::string nom, int val);
	void setParent(Item* node);
	void setChildren(TreeList* list);
	Item* getParent();
	std::string getName();
	int getType();
	TreeList* getChildren();
	virtual ~Item();
};

} /* namespace trees */

#endif /* TREENODE_HPP_ */
