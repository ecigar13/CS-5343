#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include <cmath>
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
	//write the test file
	ofstream fin1("gift1.in");
	for (int i = 0; i <20; i++)
		fin1 << rand()%130  << ' ';
	fin1.close();

	//create list
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");
	Slist* llist = new Slist();
	Slist* sortedList = new Slist();
	Snode* head = llist->getHead();
	int temp = 0;
	while (fin >> temp) { llist->insertBack(temp); }
	fin.close();

	//redirect stream to output file
	streambuf* coutbuf = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());
	
	fout << "Before sort:" << endl;
	llist->printList();

	//sort the list to another list
	//selectionSort_hard() is incomplete

	fout << "Sorting: \n";
	//llist->selectionSort_easy(sortedList);
	llist->selectionSort_hard();


	fout << "After sort:" << endl;
	//sortedList->printList();
	llist->printList();

	cout.rdbuf(coutbuf);
	//cin.get();

	fout.close();
	return 0;
}
