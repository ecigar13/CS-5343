#include "stdafx.h"
#include "MultiNode.h"
#include <iostream>
#include <fstream>
using namespace std;

void createVector(vector<vector<int>> &temp, ifstream &fin) {
	int dist = 0;
	for (auto vec : temp)
		for (auto x : vec)
		{
			fin >> dist;
			x = dist;
		}
}
int main() {
//Test case: https://mathspace.co/learn/world-of-maths/networks/adjacency-matrices-18712/adjacency-matrices-1277/

	ifstream fin("avl.in");
	ofstream fout("avl.out");

	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());

	int size = 0;
	fin >> size;
	int dist;
	vector<vector<int>> temp(size, vector<int>(size, 0));
	for(auto vec: temp)
		for (auto x : vec)
		{
			fin >> dist;
			x = dist;
		}

	Mgraph* m = new Mgraph(temp);

	fout.close();
	cout.rdbuf(coutbuf);

	cin.get();

	



}