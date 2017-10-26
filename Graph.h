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
	Mgraph(int v);
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

Mgraph::Mgraph(int v) {
	vertex = v;
	m.resize(v, vector<int>(v));
}
Mgraph::Mgraph(vector<vector<int>> &am)
{
	m = am;
	vertex = m[0].size();
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
		for (int j = 0; j < vertex; j++) {
			int temp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = temp;
		}
}

inline void Mgraph::dfs(int v)
{
}

void bfs_all(){
	//Assign unvisited to false for every vertex
	vector<bool> visited(vertex, false);
	for(unsigned int i = 0; i < vertex && unvisited[i]; i++){
		bfs(i);
	}
}

inline void Mgraph::bfs(int start)
{
	queue<int> v;
	//vector<bool> visited(vertex, false);
	v.push(i);    //push the starting vertex inside the queue
	visited[i] = true;
//while queue is ! empty
	while(!v.empty()){
		int u = q.pop_front();
		for(/*all unvisited neighbors of u, v*/){
			//visit(v);
			//add v to queue
		}
	}
	
	for (int i = 0; i < vertex; i++) {
		
		for (int j = 0; j < vertex; j++) {
			if (m[i][j] != 0 && visited[j] == false)
			{
				v.push(j);
				visited[j] = true;
			}
		}
		cout << v.front() << ' ';
		v.pop();

	}

	/*for (auto i : visited) {
		if (i == false)
			cout << "No" << endl;
	}*/
	
	//BFS, ask prof if this needs to reach every vertex

}

inline void Mgraph::notVisited()
{
}

inline void Mgraph::strongConnectivity()
{
}

