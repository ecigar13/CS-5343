//#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include "Graph.h"
using namespace std;

void createVector(vector<vector<int> > &temp, ifstream &fin) {
	for (auto & row : temp)
		for (auto & col : row)
		{
			fin >> col;
			//cout << temp[i][j];
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

	cout << "BFS: " << endl;
	graph->bfs(6);

	bool stronglyConnected = graph->strongConnectivity(6);
	cout << "Strongly connected: " << stronglyConnected << endl;



	fout.close();
	cout.rdbuf(coutbuf);

	//cin.get();
}
