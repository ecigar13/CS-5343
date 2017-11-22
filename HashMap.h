#pragma once
#include <unordered_map>
#include <iostream>
#include <string>
#include <functional>
#include <utility>
#include <assert.h>
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
	vector <string> h;	//buckets

public:
	HashMap(int least_size = 3, double _dft_LF_Rsz_Thresh = 0.5);
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
	double dft_LF_Rsz_Thresh;	//Default Load Factor Resizing Threshold
	
	int size_idx;
	int prime_sizes[] = {3, 7, 17, 37, 79, 163, 331, 673, 1361, 2729, 5471};
};

inline HashMap::HashMap(int least_size = 3, double _dft_LF_Rsz_Thresh = 0.5)
{
	//Sizes more than a maximum size are not supported
	assert(least_size <= 5471);
	
	size_idx = 0;
	while(prime_sizes[size_idx] < least_size) size_idx++;
	
	h.resize(prime_sizes[size_idx]);
	count = 0;
	
	dft_LF_Rsz_Thresh = _dft_LF_Rsz_Thresh;
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
	//Re-hash the entire table if adding the element s will lead to a load factor above the threshold
	if (double(count + 1) / h.size() > dft_LF_Rsz_Thresh){
		//Rehash existing entries and copy to bucket-structure h
		vector<string> tmp = h; // Ensure that it's a deep copy
		h.clear();
		
		size_idx++;	//resize to the next available size
		h.resize(prime_sizes[size_idx]);
		
		//re-add all elements from tmp back to the resized h
		for(auto s : tmp){
			int key = (int) myHash(s);
			while(h[key] != ""){
				key = (key + 1) % h.size();
			}
			h[key] = s;
		}
	}
	
	//Add the element s to the existing buckets
	int key = (int) myHash(s);
	while(h[key] != ""){
		key = (key + 1) % h.size();
	}
	h[key] = s;
	count++;
	return key;
}

//Will return index of the entry if found, and -1 if not
inline int HashMap::search(string & s)
{
	int key = (int) myHash(s);
	while(h[key] != ""){		//Follow linear probing
		if (s.compare(h[key]) == 0) return key;
		key = (key + 1) % h.size();
	}
	
	error("Key not found");
	return -1;
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

/*
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
*/
