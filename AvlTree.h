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
	AvlTree(TreeNode*n) :BinaryTree(n) {}
	int height(TreeNode* n);
	int diff(TreeNode* n);
	int depth(TreeNode*n);
	TreeNode* rr_rotation(TreeNode* n);
	TreeNode* rl_rotation(TreeNode* n);
	TreeNode* ll_rotation(TreeNode* n);
	TreeNode* lr_rotation(TreeNode* n);
	TreeNode*rebalance(TreeNode* n);
	TreeNode*insertLeaf(TreeNode* r, TreeNode* n);
	void setHeight(TreeNode *n);
	TreeNode* find_imbalance(TreeNode*n);
};

TreeNode * AvlTree::insertLeaf(TreeNode* r, TreeNode * n)
{
	TreeNode* temp = BinaryTree::insertLeaf(this->root, n);
	cout << "Before balancing: ";
	this->preorder(this->returnRoot());
	cout << endl;

	temp = find_imbalance(n);

	if (temp != NULL) {
		cout << "Imbalance node: " << temp->data << endl;
		TreeNode* p = temp->parent;
		if (temp == root) root = rebalance(root);
		else if (p->left == temp) {
			temp = rebalance(temp);
			p->left = temp;
		}
		else {
			temp = rebalance(temp);
			p->right = temp;
		}
		cout << "After balancing: " << endl;
		//this->printTree(this->returnRoot(), 2);
		this->preorder(this->returnRoot());

	}
	else {
		cout << "No balancing" << endl;
	}
	return temp;
}
inline TreeNode * AvlTree::find_imbalance(TreeNode * n)
{
	int i = diff(n);
	if (i < -1 || i>1) return n;

	if (n == root) return NULL;

	return find_imbalance(n->parent);
}
int AvlTree::height(TreeNode * n)
{
	int l_height = 0;
	int r_height = 0;

	if (n == NULL) return 0;
	else {
		r_height = 1 + height(n->right);
		l_height = 1 + height(n->left);
		return max(l_height, r_height);
	}
}
int AvlTree::diff(TreeNode * n)
{
	return height(n->left) - height(n->right);
}
void AvlTree::setHeight(TreeNode * n)
{
	int l_height = height(n->left);
	int r_height = height(n->right);
	n->height = max(l_height, r_height);
}
int AvlTree::depth(TreeNode * n)
{
	if (n->parent != NULL) {
		return 1 + depth(n->parent);
	}
	return 0;
}
TreeNode * AvlTree::rr_rotation(TreeNode * n)
{
	TreeNode*temp = n->right;
	n->right = temp->left;
	temp->parent = n->parent;
	n->parent = temp;
	temp->left = n;
	return temp;
}
TreeNode * AvlTree::rl_rotation(TreeNode * n)
{
	n->right = ll_rotation(n->right);
	return rr_rotation(n);
}
TreeNode * AvlTree::ll_rotation(TreeNode * n)
{
	TreeNode*temp = n->left;
	n->left = temp->right;
	temp->parent = n->parent;
	n->parent = temp;
	temp->right = n;
	return temp;
}
TreeNode * AvlTree::lr_rotation(TreeNode * n)
{
	n->left = rr_rotation(n->left);
	return ll_rotation(n);
}
TreeNode * AvlTree::rebalance(TreeNode * n)
{
	int bal = diff(n);
	if (bal > 1) {
		if (height(n->left->left) >= height(n->left->right)) {
			n = ll_rotation(n);
		}
		else {
			n = lr_rotation(n);
		}
	}
	else if (bal < -1) {
		if (height(n->right->right) >= height(n->right->left)) {
			n = rr_rotation(n);
		}
		else {
			n = rl_rotation(n);
		}
	}
	else {
		setHeight(n);
	}
	return n;
}

