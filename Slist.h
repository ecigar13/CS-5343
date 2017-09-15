#pragma once

using namespace std;

class Snode {
public:
	Snode();
	Snode(int num);
	int getVal();
	Snode* getNext();
	void setNext(Snode* tnode);
private:
	int value;
	Snode* next;
	friend class Slist;
};
Snode::Snode()
{
	value = NULL;
	next = NULL;
}
Snode::Snode(int num)
{
	value = num;
	next = NULL;
}

inline int Snode::getVal()
{
	return value;
}

inline Snode * Snode::getNext()
{
	return next;
}

inline void Snode::setNext(Snode * tnode)
{
	next = tnode;
}

class Slist {
public:
	Slist();
	~Slist();
	void removeFront();
	bool empty() const;
	void insertFront(int num);
	void insertFrontNode(Snode* temp);
	Snode* getHead();
	void printList();
	void setHead(Snode* temp);
	void selectionSort();
	void selectionSort_easy(Slist* sortedList);
	int greatestVal(Snode*n);
	Snode* greatestNode(Snode * start);
	Snode* removeNext(Snode* before);
	Snode* swapNode(Snode * head, Snode * beforeMin, Snode* min);
	
private:
	Snode* head;
};
Slist::Slist()
{
	head = NULL;
}
Slist::~Slist()
{
	while (!empty())
		removeFront();
}
void Slist::removeFront() {
	Snode* temp = head;
	head = temp->next;
	delete temp;
}
bool Slist::empty() const
{
	if (head)
		return true;
	else return false;
}
void Slist::insertFront(int num)
{
	Snode* temp = new Snode(num);
	temp->next = head;
	head = temp;
}
inline void Slist::insertFrontNode(Snode * temp)
{
	temp->next = head;
	head = temp;
}
inline Snode * Slist::getHead()
{
	return head;
}
inline void Slist::printList()
{
	Snode* temp = head;
	while (temp!=NULL) {
		cout << temp->value << ' ';
		temp = temp->next;
	}
	cout << endl;
}
inline void Slist::setHead(Snode * temp)
{
	head = temp;
}
inline Snode * Slist::swapNode(Snode * tmp, Snode * beforeMin, Snode * min)
{

	//create a circular list somewhere. Fix
	if (tmp == beforeMin)
	{
		tmp->next=min->next;
		min->next=tmp;
		return min;
	}
	else {
		Snode* temp = tmp->next;
		beforeMin->setNext(tmp);
		tmp->setNext(min->getNext());
		min->setNext(temp);
		return min;
	}
}
inline int Slist::greatestVal(Snode * n)
{
	if (n->next == NULL) { return n->value; }
	else {
		int tmp = greatestVal(n->next);
		if (tmp > n->value)
			return tmp;
		else return n->value;
	}
}

inline void Slist::selectionSort()
{
	if (head == NULL)
		return ;

	Snode* temp = head;
	Snode* temp1 = temp;
	Snode* beforeMin = temp;
	Snode* min = temp;
	int minVal = temp->value;

	//selection sort, non-recursive
	while(temp!=NULL){
		cout << endl<< "pass outer" << endl;
		Snode*s = head;
		while (s) {
			cout << s->value << ' ';
			s = s->next;
		}
		cout << endl;
		while (temp1->next != NULL) {

			if ((temp1->getNext())->getVal() <= minVal)
			{
				minVal = (temp1->getNext())->getVal();
				min = temp1->getNext();
				beforeMin = temp1;
			}
			temp1 = temp1->getNext();

		}

		if (min != temp)
			temp = swapNode(temp, beforeMin, min);

		temp = temp->next;
		temp1 = temp;

		/*Snode* s = head;
		while (s != NULL)
		{
			cout << s->value << ' ';
			cout << endl;
		}*/
	}

	
}
inline Snode * Slist::greatestNode(Snode* start)
{
	Snode* tmp = start;
	Snode* beforeMax = start;
	int max = start->value;
	while (tmp->next != NULL) {
		if (tmp->next->value > max) {
			max = tmp->next->value;
			beforeMax = tmp;
		}
		tmp = tmp->next;
	}
	return beforeMax;
}
inline void Slist::selectionSort_easy(Slist * sortedList)
{	
	while (head != NULL){	
		//insertFront, that node is the new head
		Snode* temp = head;
		Snode*maxNode = temp;
		Snode*beforeMax = temp;
		int max = temp->value;

		//find largest (keep track of beforeMax and node itself)
		while (temp->next != NULL) {
			if (temp->next->value > max) {
				beforeMax = temp;
				max = temp->next->value;
				maxNode = temp->next;
			}
			temp = temp->next;
		}

		//remove largest
		if (maxNode == head && maxNode->next == NULL) {
			sortedList->insertFrontNode(maxNode);
			head = NULL;
			continue;
		}
		if (maxNode == head) {
			head = maxNode->next;
		}
		else {
			beforeMax->next = maxNode->next;
		}

		maxNode->next = NULL;
		//insert node to other list
		sortedList->insertFrontNode(maxNode);

	}
}



inline Snode* Slist::removeNext(Snode * before)
{
	Snode*temp = before->next;
	before->next = before->next->next;
	return temp;
}


