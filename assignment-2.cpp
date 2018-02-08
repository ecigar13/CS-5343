/*
Write a program to insert numbers into a binary tree, then do an inorder traversal, preorder traversal and postorder traversal.
*/
//#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include <fstream>
#include "BinaryTree.h"
using namespace std;

int main() {

	//must create unique random numbers first

	//the input file contains a list of number to be inserted.
	ofstream fout("friday.out");
	ifstream fin("friday.in");

	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());

	int first;
	fin >> first;

	TreeNode* r =  new TreeNode(first);
	BinaryTree t = BinaryTree(r);
	while (fin >> first) {
		r = new TreeNode(first);
		t.insertLeaf(t.returnRoot(), r);
	}

	cout << "Inorder traversal: "; t.inorder(t.returnRoot()); cout << endl;
	cout << "Preorder traversal: "; t.preorder(t.returnRoot()); cout << endl;
	cout << "Postorder traversal: "; t.postorder(t.returnRoot()); cout << endl;

	cout << "Delete.\n";
	//delete fnction here.

	cout << "Inorder traversal: "; t.inorder(t.returnRoot()); cout << endl;
	cout << "Preorder traversal: "; t.preorder(t.returnRoot()); cout << endl;
	cout << "Postorder traversal: "; t.postorder(t.returnRoot()); cout << endl;
	t.print2DUtil(t.returnRoot(), 0);

	fout.close();
	cout.rdbuf(coutbuf);
	//cin.get();
	return 0;
}
