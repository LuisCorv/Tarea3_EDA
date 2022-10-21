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
}

void TreeSO::insert(Item* child, Item* parent){
	if (parent != nullptr){
		parent->getChildren()->insertFirst(child);
	}
}

void TreeSO::insert(std::string nom, int val_child, std::string nom_parent){
	Item* parent = find(nom_parent);
	if (parent != nullptr){
		Item* child = new Item(nom,val_child);
		insert(child, parent);
		std::cout << "insertado " << nom << " in " << nom_parent << " at " << parent << std::endl;
	}
}

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


void TreeSO::traverse_rec(Item* node, int level){
	if (node != nullptr){
		std::cout << std::string(level*2, '-');
		std::cout<<node->getName() <<std::endl;
		TreeList* childrenList = node->getChildren();
		TreeListNode* ptr = childrenList->getHead();
		while (ptr!=nullptr){
			traverse_rec(ptr->getData(), level + 1);
			ptr = ptr->getNext();
		}
	}
}

void TreeSO::traverse(){
	traverse_rec(root, 1);
}

TreeSO::~TreeSO() {
	delete root;
}

} /* namespace trees */
