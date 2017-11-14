#pragma once

#include <queue>
#include<vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
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
	vector<vector<int> > m;
public:
	Mgraph();
	Mgraph(vector<vector<int> > & m);
	Mgraph(int v);
	void printMatrix();
	void transposeMatrix();
	void dfs(int v);
	void dfsRecursive(int n, vector<bool>& visited);
	void bfs(int v);
	bool strongConnectivity(int begin);
	void generateMatrix();
	void resize(int v);
	void primMST();
	int minKey(vector<int> key, vector<bool> mstSet);
	void printMST(vector<int>& parent, int n);
	void topologicalDFS(int start);
	void topologicalBFS();
	
};


inline Mgraph::Mgraph()
{
	vertex = 0;
}
Mgraph::Mgraph(int v) {
	vertex = v;
	m.resize(v, vector<int>(v));
}
Mgraph::Mgraph(vector<vector<int> > &am)
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

inline void Mgraph::primMST()
{
	vector<int> parent(vertex);
	vector<int> key(vertex, INT_MAX);
	vector<bool> mstSet(vertex,false);
	key[0] = 0;
	parent[0] = -1;
	for (int count = 0; count < vertex - 1; count++) {
		
		int min = minKey(key, mstSet);
		mstSet[min] = true;

		for (int i = 0; i < vertex; i++) {
			if (m[min][i] && mstSet[i] == false && m[min][i] < key[i])
				parent[i] = min, key[i] = m[min][i];
		}
	}
	printMST(parent, vertex);
	
}

inline int Mgraph::minKey(vector<int> key, vector<bool> mstSet)
{
	int min = INT_MAX;
	int min_index=0;
	for (int i = 0; i < vertex; i++) {
		if (mstSet[i] == false && key[i] < min)
			min = key[i], min_index = i;
	}
	return min_index;
}
void  Mgraph::printMST(vector<int>& parent, int n)
{
	cout << "MST edges: "<< endl;;
	//for (int i = 1; i < vertex; i++) {
	//	//cout << parent[i] << "\t" <<  i << "\t" << m[parent[i]][i] << endl;
	//	cout << static_cast<char> ('A' + parent[i]) << "\t" << static_cast<char> ('A' + i) << "\t"<< m[parent[i]][i] << endl; 
	//	//cout << endl;
	//}

	for (int i = 0; i < vertex; i++) {
		for (int j = 1; j < vertex; j++) {
			if (parent[j] == i) {
				cout << static_cast<char> ('A' + parent[j]) << "\t" << static_cast<char> ('A' + j) << "\t" << m[parent[j]][j] << endl;
			}
		}
	}
}