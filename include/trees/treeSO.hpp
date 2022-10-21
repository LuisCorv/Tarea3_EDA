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
	Item* root;
public:
	TreeSO();
	void insert(Item* node,Item* parent);
	void insert(std::string nom, int val_child , std::string nom_parent);
	Item* find_rec(std::string nom, Item* node);
	Item* find(std::string nom);
	void traverse_rec(Item* node, int level);
	void traverse();
	virtual ~TreeSO();
};

} /* namespace trees */

#endif /* TREE_HPP_ */
