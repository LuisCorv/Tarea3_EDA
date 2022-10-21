/*
 * childNode.hpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */

#ifndef CHILDNODE_HPP_
#define CHILDNODE_HPP_

#include "trees/Item.hpp"

namespace trees {
class Item;
class TreeListNode {
private:
	Item* data;
	TreeListNode* ptrNext;

public:
	TreeListNode();
	TreeListNode(Item* _data, TreeListNode* next = nullptr);
	void setData(Item* _data);
	void setNext(TreeListNode* _next);
	Item* getData();
	TreeListNode* getNext();
	virtual ~TreeListNode();
};

} /* namespace trees */

#endif /* CHILDNODE_HPP_ */
