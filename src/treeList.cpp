/*
 * childrenList.cpp
 *
 *  Created on: Aug 31, 2022
 *      Author: jsaavedr
 */

#include "trees/treeList.hpp"
#include <iostream>
namespace trees {

TreeList::TreeList(): head(nullptr) {
	// TODO Auto-generated constructor stub
}

void TreeList::insertFirst(Item* treeNode){
	TreeListNode* node = new TreeListNode(treeNode);
	if (head == nullptr) {
		head = node;
	}
	else{
		node->setNext(head);
		head = node;
	}
}

TreeListNode* TreeList::getHead(){
	return head;
}

void TreeList::removeFirst(){
	TreeListNode* ptr = head;
	if (head != nullptr){
		head = head->getNext();
		delete ptr;
	}
}


void TreeList::remove(std::string nom){
	TreeListNode* ptr = head;
	TreeListNode* ptr_prev = nullptr;
	while (ptr != nullptr){
		if ((ptr->getData())->getName() == nom){
			//erase node
			if (ptr_prev == nullptr) {
				head = ptr->getNext();
				delete ptr;
				ptr = head;
			}
			else{
				ptr_prev->setNext(ptr->getNext());
				delete ptr;
				ptr = ptr_prev->getNext();
			}
		}
		else{
			ptr_prev = ptr;
			ptr = ptr->getNext();
		}
	}
}

void TreeList::removeAll(){
	while (head != nullptr){
		removeFirst();
	}
}

Item* TreeList::find(std::string nom){
	TreeListNode* ptr = head;
	while ((ptr != nullptr) && ((ptr->getData())->getName() != nom)){
		ptr = ptr->getNext();
	}
	return ptr->getData();
}

bool TreeList::isEmpty(){
	return (head == nullptr);
}


TreeList::~TreeList() {
	removeAll();
}





} /* namespace trees */


