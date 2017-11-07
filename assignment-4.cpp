#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include "Graph.h"
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
	//Test case: https://www.math.ucdavis.edu/~daddel/linear_algebra_appl/Applications/GraphTheory/GraphTheory_9_17/node9.html

	ifstream fin("avl.in");
	ofstream fout("avl.out");

	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());

	int size = 0;
	fin >> size;
	int dist;

	vector<vector<int>> temp(size, vector<int>(size, 0));
	for (auto vec : temp)
		for (auto x : vec)
		{
			fin >> dist;
			x = dist;
		}

	for (auto vec : temp) {
		for (auto x : vec)
		{
			cout << x;
		}
		cout << endl;
	}
	/*Mgraph* graph = new Mgraph(temp);

	graph->printMatrix();*/
	fout.close();
	cout.rdbuf(coutbuf);

	//cin.get();





}