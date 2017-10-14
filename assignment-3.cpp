//#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include <fstream>
#include <stdio.h>
#include <string>

//#include "BinaryTree.h"
//#include "Slist.h"
#include "AvlTree.h"
using namespace std;


int main() {

	ifstream fin("avl.in");
	ofstream fout("avl.out");

	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());
	int temp;
	fin >> temp;
	TreeNode* n = new TreeNode(temp);
	AvlTree* t = new AvlTree(n);
	t->preorder(t->returnRoot());

	while (fin >> temp) {
		n = new TreeNode(temp);

		cout << endl << "Insert: " << temp << endl;
		t->insertLeaf(t->returnRoot(), n);

		cout << endl;
	}
	cout << "Preorder traversal: ";
	t->preorder(t->returnRoot());
	fout.close();
	cout.rdbuf(coutbuf);
	//cin.get();
	return 0;
}

