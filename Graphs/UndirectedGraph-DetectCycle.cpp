#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

struct Edge
{
	int source;
	int destination;
};

struct Graph
{

	Graph(const int V, const int E);
	~Graph();
	int find(int parent[]. const int i)'
	bool isCyle() const;

	int 		m_V;		 //< The number of vertice.
	int 		m_E;		 //< The number of edge.
	Edge 		*m_pEdgeList;	 //< The list of edges.
};


Graph::Graph (const int V, const int E) : 
m_V(V),
m_E(E),
m_pEdgeList(new Edge[m_E])
{
}

Graph::~Graph()
{
	delete [] m_pEdgeList;
}

int Graph::find((int parent[], const int i)
{
	if (parent[i] == -1)
		return i;

	return find(parent[i]);
}

void Union(int parent[], const int src, const int des)
{
	parent[find(parent, src)] = find(parent, des);
}

bool isCyle(const Graph &graph)
{
	int *parent = new int[graph.m_V];
}

int main ()
{
	cout << "Hello\n";
	return 0;
}
