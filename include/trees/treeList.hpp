/*
 * childrenList.hpp
 *
 *  Created on: Aug 31, 2022
 *      Author: jsaavedr
 */

#ifndef CHILDRENLIST_HPP_
#define CHILDRENLIST_HPP_

#include "trees/treeListNode.hpp"
#include <iostream>

namespace trees {

class Item;
class TreeListNode;
class TreeList {
private:
	TreeListNode* head;
public:
	TreeList();
	TreeListNode* getHead();
	void insertFirst(Item* treeNode);
	void removeFirst();
	void remove(std::string nom);
	void removeAll();
	bool isEmpty();
	Item* find(std::string nom);
	virtual ~TreeList();
};

} /* namespace trees */

#endif /* CHILDRENLIST_HPP_ */
