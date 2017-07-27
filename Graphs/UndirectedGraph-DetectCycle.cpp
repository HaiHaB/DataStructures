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
	int find(int parent[], const int i);
	void Union(int parent[], const int src, const int des);
	bool isCyclic();

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

int Graph::find(int parent[], const int i)
{
	if (parent[i] == -1)
		return i;

	return find(parent, parent[i]);
}

void Graph::Union(int parent[], const int src, const int des)
{	
	std::cout << "src = " << src << "; des = " << des << std::endl;
	std::cout << "Parent[" << find(parent, src) << "] = " << find(parent, des) << std::endl;
	parent[find(parent, src)] = find(parent, des);
}

bool Graph::isCyclic()
{
	int *parent = new int[m_V];
	for (int i = 0; i < m_V; ++i)
		parent[i] = -1;

	for (int i = 0; i < m_V; ++i)
	{
		int x = find(parent, m_pEdgeList[i].source);
		int y = find(parent, m_pEdgeList[i].destination);

		if (x == y)
			return true;
		
		Union(parent, x, y);
	}
	return false;
}

int main ()
{
	cout << "Hello\n";

	// 0
	// | \
	// |  \
	// 1---2

	Graph graph(3,3);

	// Edge (0,1)
	graph.m_pEdgeList[0].source = 0;
	graph.m_pEdgeList[0].destination = 1;

	// Edge (1,2)
	graph.m_pEdgeList[1].source = 1;
	graph.m_pEdgeList[1].destination = 2;

	// Edge (0,2)
	graph.m_pEdgeList[2].source = 0;
	graph.m_pEdgeList[2].destination = 2;
		
	std::cout << (graph.isCyclic() ? "Graph contains cycle" : "Graph does not contain cycle") << std::endl;
	return 0;
}
