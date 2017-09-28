#pragma once
#include<algorithm>

using namespace std;
class TreeNode {
private:
	int data;
	TreeNode * left;
	TreeNode* right;
	TreeNode* parent;
	friend class BinaryTree;
public:
	TreeNode();
	TreeNode(int val);
	TreeNode(int val, TreeNode* l, TreeNode* r);

	int getData();
	TreeNode* getLeft();
	TreeNode* getRight();
	TreeNode* getParent();
	bool isRoot();
	bool isExternal();
};

class BinaryTree {
private:
	TreeNode* root;
	int size=0;
public:
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
	TreeNode* min(TreeNode*n);
	TreeNode* max(TreeNode*n);
	TreeNode* sibling(TreeNode* r, int key);
	TreeNode* parent(TreeNode* r, int key);
	TreeNode* parentNormalTree(TreeNode* r, int key);
	TreeNode* insertLeaf(TreeNode* r, TreeNode* n);  //duplicate inserts right
	void print2DUtil(TreeNode *r, int space);
	TreeNode* deleteNode(TreeNode* r, TreeNode* n);
};

inline BinaryTree::BinaryTree(TreeNode* r)
{
	root = r;
	size++;
}
inline TreeNode * BinaryTree::returnRoot()
{
	return root;
}
inline int BinaryTree::countNodes(TreeNode* r)
{
	if (r = NULL)
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
	preorder(r->left);
	preorder(r->right);
	cout << r->data << ' ';
}
inline void BinaryTree::inorder(TreeNode * r)
{
	if (r == NULL)
		return;
	preorder(r->left);
	cout << r->data << ' ';
	preorder(r->right);
	
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
	n = n->left;
	while (n->right != NULL) n = n->right;
	return n;

}
inline TreeNode * BinaryTree::min(TreeNode * n)
{
	if (n == NULL)
		return NULL;
	return min(n->left);
}
inline TreeNode * BinaryTree::max(TreeNode * n)
{
	if (n == NULL)
		return NULL;
	return max(n->right);
}
inline TreeNode * BinaryTree::sibling(TreeNode * r, int key)
{	if (r==NULL || r->data==key)
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
	if(root==NULL)	return NULL;
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
	if(root==NULL)
	return NULL;
	if (root->left->data == key || root->right->data==key)
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
	return (parent==false);
}
inline bool TreeNode::isExternal()
{
	return (left==NULL && right==NULL);
}


void BinaryTree::print2DUtil(TreeNode *r, int space)
{
	// Base case
	if (r == NULL)
		return;

	// Increase distance between levels
	space += 10;

	// Process right child first
	print2DUtil(r->right, space);

	// Print current node after space
	// count
	//cout << endl;
	for (int i = 10; i < space; i++)
		cout<<' ';
	cout<< r->data<<endl;

	// Process left child
	print2DUtil(r->left, space);
}
TreeNode* BinaryTree::deleteNode(TreeNode * r, TreeNode * n)
{
	//root==NULL
	//if it's a leaf, delete
	//if it has 1 child, bring child up 
	//if it has 2 children, bring successor up, delete successor leaf node

	if (r == NULL)
		return false;
	if (n->left == NULL && n->right == NULL)
		delete n;
	if (n->left == NULL) {
		n->parent->
	}
}
