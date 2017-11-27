//#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include "HashMap.h"
using namespace std;

int main() {
	ifstream fin("hash.in");
	ofstream fout("hash.out");
	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());

	//read the file
	vector<string> v;
	string temp;
	while (true) {
		if (fin.eof())   //eof is set right after reading the last line.
			break;
		getline(fin, temp);
		v.push_back(temp);
	}

	HashMap * t = new HashMap(3, 0.5);

	cout << endl<< "Adding strings: " << endl;
	for (auto i : v)
	{
		cout << i << endl;
		t->add(i);
		cout << "Table size: " << t->getSize() << endl;
	}
	
	cout <<endl<< "Printing map: " << endl;
	t->printMap();

	int s = rand() % v.size();
	cout << "Searching: " << v[s] << endl;
	cout << "Search result: " << t->search(v[s]) << endl;

	cout << "Deleting: " << v[s] << endl;
	t->remove(v[s]);

	cout << "Searching: " << v[s] << endl;
	cout << "Search result: " << t->search(v[s]) << endl;
	fout.close();
	cout.rdbuf(coutbuf);
	cout << "Check hash.out file." << endl;
	//cin.get();
}
