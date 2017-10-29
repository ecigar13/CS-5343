#pragma once

#include <queue>
#include<vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
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
	Mgraph(int v);
	void printMatrix();
	void transposeMatrix();
	void dfs(int v);
	void dfsRecursive(int n, vector<bool>& visited);
	void bfs(int v);
	bool strongConnectivity(int begin);
	void generateMatrix();
	void resize(int v);
};


inline Mgraph::Mgraph()
{
	vertex = 0;
}
Mgraph::Mgraph(int v) {
	vertex = v;
	m.resize(v, vector<int>(v));
}
Mgraph::Mgraph(vector<vector<int>> &am)
{
	m = am;
	vertex = m.size();
}
inline void Mgraph::printMatrix()
{
	cout << "Vertices: " << vertex << endl;
	for (auto row : m) {
		for (auto col : row)
		{
			cout << col << ' ';
		}
		cout << endl;
	}
}
inline void Mgraph::transposeMatrix() {
	for (int i = 0; i < vertex; i++)
		for (int j = i; j < vertex; j++) {
			int temp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = temp;
		}
}
inline void Mgraph::dfs(int begin)
{
	int start = begin - 1;
	vector<bool> visited(vertex, false);
	dfsRecursive(start, visited);
	//call dfsRecursive
}
inline void Mgraph::dfsRecursive(int start, vector<bool> & visited) {
	visited[start] = true;
	cout << start + 1 << ' ';
	for (int i = 0; i < vertex; i++)
	{
		if (m[start][i] != 0 && visited[i] == false) {
			dfsRecursive(i, visited);
		}

	}
}
inline void Mgraph::bfs(int begin)
{
	int start = begin - 1;    //convert to array index;
	queue<int> q;
	vector<bool> visited(vertex, false);
	q.push(start);    //push the starting vertex inside the queue
	visited[start] = true;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		cout << u + 1 << ' ';
		for (int j = 0; j < vertex; j++) {
			if (m[u][j] != 0 && visited[j] == false) {
				q.push(j);
				visited[j] = true;
			}
		}
	}
	cout << endl;
}
inline bool Mgraph::strongConnectivity(int begin)
{
	//Kosaraju's algo
	vector<bool> visited(vertex, false);

	cout << "DFS: ";
	this->dfsRecursive(begin - 1, visited);
	cout << endl;
	for (auto row : visited)
		if (row == false)
			return false;

	this->transposeMatrix();
	for (int i = 0; i < vertex; i++)
		visited[i] = false;
	cout << "DFS: ";
	this->dfsRecursive(begin - 1, visited);
	cout << endl;

	this->transposeMatrix();
	for (auto row : visited)
		if (row == false)
		{
			return false;
		}
		else return true;

		//dfs traversal
		//reverse all edges
		//mark visited vector as unvisited
		//dfs traversal again
		//if every node can be reached from a vertex then it's strongly connected
}
inline void Mgraph::generateMatrix()
{
	int count = 17;
	srand(time(NULL));
	for (int i = 0; i < vertex; i++)
		for (int j = 0; j < vertex; j++)
		{
			int temp=rand() % 2;
			if (temp != 0 && count !=0)
			{
				count--;
				m[i][j] = temp;

			}
		}
}
inline void Mgraph::resize(int newSize)
{
	vertex = newSize;
	m.resize(newSize, vector<int>(newSize));
}
