#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include "HashMap.h"
using namespace std;

void createVector(vector<vector<int> > &temp, ifstream &fin) {
	for (unsigned int i = 0; i < temp.size(); i++)
		for (unsigned int j = 0; j < temp.size(); j++)
		{
			fin >> temp[i][j];
			if (i != j && temp[i][j] == 0)
				temp[i][j] = NULL;
			if (i == j && temp[i][j] != 0)
				temp[i][j] = 1;
		}
}
int main() {


	//use graph.in for not strongly connected. Use graph1.in for strongly connected.
	ifstream fin("hash.in");
	ofstream fout("hash.out");

	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());

	//read the file
	vector<string> v;
	string temp;
	while (true) {
		getline(fin, temp);
		if (fin.eof())
			break;
		v.push_back(temp);
	}
	for (auto i : v)
		cout << i << endl;

	HashMap t = new HashMap(3);


	fout.close();
	cout.rdbuf(coutbuf);

	cin.get();
}
