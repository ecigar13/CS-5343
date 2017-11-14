//#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include "Graph.h"
using namespace std;

void createVector(vector<vector<int> > &temp, ifstream &fin) {
	for (unsigned int i=0; i < temp.size();i++)
		for (unsigned int j=0; j < temp.size();j++)
		{
			fin >> temp[i][j];
			if (i != j && temp[i][j] == 0)
				temp[i][j] = NULL;
			if(i==j && temp[i][j]!=0)
				temp[i][j] = 1;
		}
}
int main() {
	

	//use graph.in for not strongly connected. Use graph1.in for strongly connected.
	ifstream fin("graph.in");
	ofstream fout("graph.out");

	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());

	int size = 0;
	fin >> size;

	vector<vector<int> > temp(size, vector<int>(size, 0));
	createVector(temp, fin);

	Mgraph* graph = new Mgraph(temp);


	cout << "Print matrix: " << endl;
	graph->printMatrix();

	graph->primMST();

	fout.close();
	cout.rdbuf(coutbuf);

	//cin.get();
}
