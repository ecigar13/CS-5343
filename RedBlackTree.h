#pragma once

#include "AvlTree.h"

class RedBlackTree :public BinaryTree, public AvlTree {

public:
	TreeNode * insertLeaf(TreeNode * r, TreeNode * n);

};

TreeNode* RedBlackTree::insertLeaf(TreeNode* r, TreeNode * n)
{
	TreeNode* temp = BinaryTree::insertLeaf(this->root, n);
	if (root == temp) { temp->setColor(true); }
	//continue here
}