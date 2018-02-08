#pragma once
#include<algorithm>

using namespace std;
class TreeNode {
private:
	int data;
	TreeNode * left;
	TreeNode* right;
	TreeNode* parent;
	int height;
	bool isBlack;
	friend class BinaryTree;
	friend class AvlTree;
public:
	TreeNode();
	TreeNode(int val);
	TreeNode(int val, TreeNode* l, TreeNode* r);

	int getData();
	TreeNode* getLeft();
	TreeNode* getRight();
	TreeNode* getParent();
	bool isRoot();
	void setColor(bool black);
	bool getColor(TreeNode* n);
	
};

class BinaryTree {
private:
	TreeNode* root;
	int size;
public:
	BinaryTree() { size = 0; root = NULL; };
	BinaryTree(TreeNode* r);
	TreeNode* returnRoot();
	int countNodes(TreeNode* r);
	int countLeaf(TreeNode* r);
	int  largestValue(TreeNode* r);
	void preorder(TreeNode* r);
	void postorder(TreeNode* r);
	void inorder(TreeNode* r);
	TreeNode* predecessor(TreeNode*n, int key);
	TreeNode* successor(TreeNode* n, int key);
	TreeNode* predecessorNode(TreeNode*n);
	TreeNode* successorNode(TreeNode*n);
	TreeNode* min(TreeNode*n);
	TreeNode* maxNode(TreeNode*n);
	TreeNode* sibling(TreeNode* r, int key);
	TreeNode* parent(TreeNode* r, int key);
	TreeNode* parentNormalTree(TreeNode* r, int key);
	TreeNode* insertLeaf(TreeNode* r, TreeNode* n);
	bool isExternal(TreeNode * n);
	//duplicate inserts right
	void printTree(TreeNode *r, int space);
	TreeNode* deleteNode(TreeNode* r, int n);

	friend class AvlTree;
	friend class RedBlackTree;
};

inline BinaryTree::BinaryTree(TreeNode* r)
	:root(r), size(1)
{
	root = r;
	size=1;
}
inline TreeNode * BinaryTree::returnRoot()
{
	return root;
}
inline int BinaryTree::countNodes(TreeNode* r)
{
	if (r == NULL)
		return 0;
	else return 1 + countNodes(r->left) + countNodes(r->right);
}
inline int BinaryTree::countLeaf(TreeNode * r)
{
	if (r->left == NULL && r->right == NULL)
		return 1;
	else return countLeaf(r->left) + countLeaf(r->right);
}
inline int BinaryTree::largestValue(TreeNode * root)
{/*if(root->left==NULL && root->right==NULL)
 return root->data;
 if(root->left==NULL){
 return(max(root->data, largestValue(root->right)));
 }
 if (root->right == NULL) {
 return (max(root->data, largestValue(root->left)));
 }
 return max(root->data, largestValue(root->left), largestValue(root->right));*/
}
inline void BinaryTree::preorder(TreeNode*r)
{
	if (r == NULL)
		return;
	cout << r->data << ' ';
	preorder(r->left);
	preorder(r->right);

}
inline void BinaryTree::postorder(TreeNode * r)
{
	if (r == NULL)
		return;
	postorder(r->left);
	postorder(r->right);
	cout << r->data << ' ';
}
inline void BinaryTree::inorder(TreeNode * r)
{
	if (r == NULL)
		return;
	inorder(r->left);
	cout << r->data << ' ';
	inorder(r->right);

}
inline TreeNode * BinaryTree::predecessor(TreeNode * n, int key)
{
	while (n != NULL && n->data != key) {
		if (n->data < key) { n = n->right; }
		else n = n->left;
	}
	if (n == NULL) return NULL;
	if (n->data == key&& n->left == NULL) return NULL;
	n = n->left;
	while (n->right != NULL) n = n->right;
	return n;
	return NULL;
}
inline TreeNode * BinaryTree::successor(TreeNode * n, int key)
{
	while (n != NULL && n->data != key) {
		if (n->data < key) n = n->right;
		else n = n->left;
	}
	if (n == NULL) return NULL;
	if (n->data == key && n->left == NULL) return NULL;
	n = n->right;
	while (n->left != NULL) n = n->left;
	return n;

}
inline TreeNode * BinaryTree::predecessorNode(TreeNode * n)
{
	return maxNode(n->left);
}
inline TreeNode * BinaryTree::successorNode(TreeNode * n)
{
	return min(n->right);
}
inline TreeNode * BinaryTree::min(TreeNode * n)
{
	if (n->left == NULL)
		return n;
	return min(n->left);
}
inline TreeNode * BinaryTree::maxNode(TreeNode * n)
{
	if (n->right == NULL)
		return n;
	return maxNode(n->right);
}
inline TreeNode * BinaryTree::sibling(TreeNode * r, int key)
{
	if (r == NULL || r->data == key)
		return NULL;
	TreeNode* tmp = NULL;
	if (r->left != NULL) {
		if (r->left->data == key) return r->right;
		tmp = sibling(r->left, key);
	}
	if (tmp == NULL) {
		if (r->right != NULL) {
			if (r->right->data == key) return r->left;
			tmp = sibling(r->right, key);
		}
	}
	return tmp;
}
inline TreeNode * BinaryTree::parent(TreeNode * root, int key)
{
	//only works in BST
	if (root == NULL)	return NULL;
	if (root->data > key) {
		if (root->left->data == key)
			return root;
		else return parent(root->left, key);
	}
	else {
		if (root->right->data == key)
			return root;
		else return parent(root->right, key);
	}
}
inline TreeNode * BinaryTree::parentNormalTree(TreeNode * root, int key)
{
	if (root == NULL)
		return NULL;
	if (root->left->data == key || root->right->data == key)
		return root;
	else {
		TreeNode* tmp = parentNormalTree(root->left, key);
		if (tmp == NULL)
			tmp = parentNormalTree(root->right, key);
		return tmp;
	}
}
inline TreeNode*  BinaryTree::insertLeaf(TreeNode* r, TreeNode * n)
{
	if (r == NULL) {
		//cout << n->data << endl;
		this->size++;
		return n;
	}
	if (r->data > n->data) {
		r->left = insertLeaf(r->left, n);
		r->left->parent = r;
	}
	else if (r->data <= n->data) {
		r->right = insertLeaf(r->right, n);
		r->right->parent = r;
	}
	return r;
}
inline TreeNode::TreeNode()
{
	left = NULL;
	right = NULL;
	parent = NULL;
}
inline TreeNode::TreeNode(int val)
{
	data = val;
	left = NULL;
	right = NULL;
}
inline TreeNode::TreeNode(int val, TreeNode * l, TreeNode * r)
{
	data = val;
	left = l;
	right = r;
}
inline int TreeNode::getData()
{
	return data;
}
inline TreeNode * TreeNode::getLeft()
{
	return left;
}

inline TreeNode * TreeNode::getRight()
{
	return right;
}
inline TreeNode * TreeNode::getParent()
{
	return parent;
}

inline bool TreeNode::isRoot()
{
	return (parent == false);
}
inline void TreeNode::setColor(bool black)
{
	isBlack = black;
}
inline bool TreeNode::getColor(TreeNode * n)
{
	return n->isBlack;
}
inline bool BinaryTree::isExternal(TreeNode*n)
{
	return (n->getLeft() == NULL && n->getRight() == NULL);
}

/* This function prints graphical version of a tree. You need to supply pointer to the root of a tree
* and spacing in the tree. I usually go with 3.
* TreeNode *r : root of any binary tree.
* int space : spacing in the tree. Larger number means more space. 
*/
void BinaryTree::printTree(TreeNode *r, int space)
{
	//reverse preorder traversal, including spaces
	if (r == NULL)
		return;
	space += 3;
	printTree(r->right, space);
	for (int i = 5; i < space; i++)
		cout << '-';
	cout << r->data<< endl;
	printTree(r->left, space);
}
TreeNode* BinaryTree::deleteNode(TreeNode * r, int n)
{
	//root==NULL
	//if it's a leaf, delete
	//if it has 1 child, bring child up 
	//if it has 2 children, bring successor up, delete successor leaf node

	if (r == NULL)
		return r;
	if (n < r->data)
		r->left = deleteNode(r->left, n);
	else if (n > r->data)
		r->right = deleteNode(r->right, n);
	else {
		if (r->left == NULL) {
			TreeNode* temp = r->right;
			delete r;
			return temp;
		}
		else if (r->right == NULL) {
			TreeNode* temp = r->left;
			delete r;
			return temp;
		}
		TreeNode* temp = successorNode(r);
		r->data = temp->data;
		r->right = deleteNode(r->right, temp->data);
	}
	return r;

}


