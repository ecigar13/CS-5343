#pragma once

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


class Mgraph {
private:
	int vertex;
	vector<vector<int>> m;
public:
	Mgraph();
	Mgraph(vector<vector<int>> & m);
	Mgraph(int nodes);
	void printMatrix();
	void transposeMatrix();
	void dfs(int v);
	void bfs(int v);
	void notVisited();
	void strongConnectivity();
};


inline Mgraph::Mgraph()
{
}

Mgraph::Mgraph(int size) {
	vertex = size;
	m.resize(size, vector<int>(size));
}
Mgraph::Mgraph(vector<vector<int>> &am)
{
	m = am;
	vertex = m[0].size();
}

inline void Mgraph::printMatrix()
{
	for (int i = 0; i < vertex; i++)
		for (int j = 0; j < vertex; j++)
			cout << m[i][j] << "\t";
	cout << "\n";
}

inline void Mgraph :: transposeMatrix() {
	for (int i = 0; i < vertex; i++)
		for (int j = 0; j < vertex; j++) {
			int temp= m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = temp;
		}	
}

inline void Mgraph::dfs(int v)
{
}

inline void Mgraph::bfs(int v)
{
}

inline void Mgraph::notVisited()
{
}

inline void Mgraph::strongConnectivity()
{
}

