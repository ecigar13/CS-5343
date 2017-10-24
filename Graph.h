#pragma once

#include "BinaryTree.h"
#include <queue>
#include<vector>
#include <iostream>

using namespace std;
//1. Write a program to do BFS traversal of a graph.
//You will first create a graph.Use Adjacency Matrix for graph representation.You may use a queue library to do the traversal.The graph must have at least 10 nodes and 15 edges.
//Submit screen shot of execution of the program.Also draw the graph on a paper and scan it and submitt it to show the graph you are doing BFS on.
//2. Write a program that returns true if the graph is strongly connected.Else it returns true.
//Create the graph as in 1. above, using adjacency matrix.
//run the program on two graphs.A strongly connected graph and also a graph not strongly connected.Submit screen shot of execution for both the graphs.Also submit scanned copies of the graph.


class mGraph {
private:
	int nodes;
	vector<vector<int>> m;
public:

	mGraph(vector<vector<int>> & m);
	mGraph(int nodes);
	void printMatrix();
};


mGraph::mGraph(vector<vector<int>> &am)
{
	m = am;
	nodes = m[0].size();
}

inline mGraph::mGraph(int n)
{
	m.resize(n, vector<int>(n, 0));
	nodes = n;
}

inline void mGraph::printMatrix()
{
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++)
			cout << m[i][j] << "\t";
		cout << "\n";
}
}

