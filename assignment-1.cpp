
//#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include <cmath>
#include <random>
#include <string>
#include <fstream>
#include <map>

#include "Slist.h"

using namespace std;


/*1. Write a program to sort a single linked list to ascending order.  The linked list will have positive numbers in each node. Use selection sort algorithm .
2. You will not use any library functions. You must create your own linked list. Initially the list will be unsorted.
3. The list must have at least 15 nodes.
4. Submit the code.
5. Submit screen shots of execution.  You must print the traversed list before sorting.
Then print the traversed list after it is sorted. */

int main() {
	ofstream fin1("gift1.in");
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");

	for (int i = 0; i < 20; i++)
		fin1 << rand()%300  << ' ';

	fin1.close();

	//create new list
	//read in and create nodes (add front)
	Slist* llist = new Slist();
	Slist* sortedList = new Slist();
	Snode* head = llist->getHead();
	int temp = 0;

	while (fin >> temp) { llist->insertFront(temp); }
	fin.close();


	streambuf* coutbuf = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());
	
	fout << "Before sort:" << endl;
	llist->printList();


	llist->selectionSort_easy(sortedList);

	fout << "After sort:" << endl;
	sortedList->printList();

	cout.rdbuf(coutbuf);
	//cin.get();

	fout.close();
	return 0;
}
