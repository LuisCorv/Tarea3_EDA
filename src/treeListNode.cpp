/*
 * childNode.cpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */

#include "trees/treeListNode.hpp"

namespace trees {

TreeListNode::TreeListNode(): data(), ptrNext(nullptr) {
	// TODO Auto-generated constructor stub

}

TreeListNode::TreeListNode(Item* _data,
		TreeListNode* next) : data(_data), ptrNext(next){

}
void TreeListNode::setData(Item* _data){
	data = _data;
}
void TreeListNode::setNext(TreeListNode* _next){
	ptrNext = _next;
}
Item* TreeListNode::getData(){
	return data;
}
TreeListNode* TreeListNode::getNext(){
	return ptrNext;
}

TreeListNode::~TreeListNode() {
	//Actions when a TreeListNode is deleted
	delete data;
}

} /* namespace trees */
