#pragma once
#include <unordered_map>
#include <iostream>
#include <string>
#include <functional>
#include <utility>
using namespace std;
//You may pick a hashing algorithm to use from standard library.But you must implement the function s to add, search and delete from the hash table.
//The collision resolution should be done using open address scheme, linear probe.
//The hash table would consist of arbitrary strings of any size.
//
//Also your program must keep track of number of collisions that happen when you add a string.After each string is added, print the number of collisions for that string.
//If the load factor becomes greater than .5, then double the table size to next prime number.
//
//Add at least 15 strings to the table.Each string ranging from 5 characters each to 10 characters.There should be a mix of these sizes.
//Execute your program to add the strings.
//
//Then search for a string added to the table.IT should return the index of the table entry.
//Then search for a string not in the table, return a suitable error message
//
//Delete a string previously added, before the delete, show it is there.Then delete the string and run search on it.
//Finally, show that your program doubles the table size when load factor becomes more than .5
//
//So your initial table size should be less than half the size of # of strings you will add.
//Submit the code as well as screen shot of these.

class HashMap {
protected:
	vector < string> h;

public:
	HashMap(int initialSize);
	size_t myHash(string& s);
	void doubleSize();
	double loadFactor();
	int count;
	int collision;
	int add(string& s);
	int search(string& s);
	void remove(string& s);
	void printMap();
	int linearProbing(int i);
};

inline HashMap::HashMap(int initialSize)
{
	h.resize(initialSize);
	count = 0;
}

size_t HashMap::myHash(string& s) {
	return hash<string>{}(s) % h.size();
}

inline void HashMap::doubleSize()
{

	if (loadFactor() > 0.5)
		h.resize(h.size() * 2);
}

inline double HashMap::loadFactor()
{
	return ((double)count) / h.size();
}

inline int HashMap::add(string & s)
{
//need to add: when load factor is > 0.5, double the size and rehash the table.
	int key = myHash(s);
	while (true)
		if (h[key] == "")
		{
			h[key] = s;
			return key;
		}
	key++;
	if (key >= h.size() - 1)
		key %= h.size();
}

inline int HashMap::search(string & s)
{
	int key = myHash(s);
	while (h[key] != "")
		if (s.compare(h[key]) == 0)
			return key;
	key++;
	if (key >= h.size() - 1)
		key %= h.size();

}
inline void HashMap::remove(string & s)
{
	int key = myHash(s);
	while (h[key] != "") {
		if (s.compare(h[key]) == 0) {
			h[key] = "";
			return;
		}
		key++;
		if (key >= h.size() - 1)
			key %= h.size();

	}
}

inline void HashMap::printMap()
{
	for (int i = 0; i < h.size(); i++) {
		cout << i << "\t\t\t" << h[i] << endl;
	}
}


inline int HashMap::linearProbing(int i)
{
	int j = i;
	while (true) {
		if (j > h.size() - 1)
			j = (j + 1) % h.size();
		if (h[j] == "")						//might have logic error here.
			return j;
		else j++;
	}
}
