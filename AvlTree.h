#pragma once

#include<algorithm>
#include "BinaryTree.h"

//implement the insert operation for the AVL tree.
//Insert the following in the order I have given :
//40, 20, 10, 15, 13, 60, 80, 100, 90, 120, 85, 12, 14, 11, 4, 1, 3, 2
//At the end do a inorder traverse to print the node values.
//Submit the code

class AvlTree :public BinaryTree {


public:
	int height(TreeNode* n);
	int diff(TreeNode* n);
	int depth(TreeNode*n);
	TreeNode* rr_rotation(TreeNode* n);
	TreeNode* rl_rotation(TreeNode* n);
	TreeNode* ll_rotation(TreeNode* n);
	TreeNode* lr_rotation(TreeNode* n);
	TreeNode*balance(TreeNode* n);
	TreeNode*insertLeaf(TreeNode* n) override;

};
