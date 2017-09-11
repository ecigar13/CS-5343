
/*1. Write a program to sort a single linked list to ascending order.  The linked list will have positive numbers in each node. Use selection sort algorithm .
2. You will not use any library functions. You must create your own linked list. Initially the list will be unsorted.
3. The list must have at least 15 nodes.
4. Submit the code.
5. Submit screen shots of execution.  You must print the traversed list before sorting.
Then print the traversed list after it is sorted. */


//#include "stdafx.h"
#include <iostream>
#include<algorithm>
#include <cmath>
#include <random>
#include <string>
#include <fstream>
#include <map>

using namespace std;


struct node {
	struct node* next;
	int value;
};

node* swapNode(node* head, node*beforeMin,node* min )
{
	//swap has problem. It creates infinite loop at 34 9...
	if (head == beforeMin)
	{
		head->next = min->next;
		min->next = head;
		return min;
	}

	node* temp = new node;
	temp= head->next;
	beforeMin->next = head;
	head->next = min->next;
	min->next = temp;

	return min;
}



node* selectionSort(node* head)
{
	if (head == NULL)
	{
		return head;
	}

	node* beforeMin = head;
	node* min = head;
	node* temp = head;
	int minVal = head->value;

	while (temp->next != NULL) {
		if (temp->next->value < minVal)
		{
			minVal = temp->next->value;
			beforeMin = temp;
			min = temp->next;
		}
		temp = temp->next;
	}

	if(min != head)
		head = swapNode(head, beforeMin, min);
	head->next = selectionSort(head->next);
	return head;
}

void printSList(node* head, ofstream& fout)
{
	node* temp = head;
	while (temp != NULL)
	{
		fout << temp->value << ' ';
		temp = temp->next;
	}
	fout << endl;
}
int main() {
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");

	node* head;
	node* temp1;
	node* temp2;

	head = new node;
	fin >> head->value;
	head->next = temp1;
	temp1 = head;
	
	int num = 0;
	while (fin >> num)
	{
		temp2 = new node;
		temp2->value = num;
		temp2->next = NULL;
		temp1 ->next= temp2;
		temp1 = temp2;
	}

	fout << "Before sort:" << endl;
	printSList(head, fout);
	head = selectionSort(head);
	fout << "After sort:" << endl;
	printSList(head, fout);

	fout.close();
	return 0;
}
