// C++ program for Kruskal's algorithm to find Minimum Spanning Tree
// of a given connected, undirected and weighted graph
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//http://www.geeksforgeeks.org/?p=26604

struct Edge
{
	int 	m_src;
	int 	m_dest;
	int	m_weight;
	
	Egde(const int src, const in dest, const int weight) :
		m_src(src), m_dest(dest), m_weight(weight)
	{
		
	}
};

class Graph 
{
public:
	Graph(const int V, const int E);
	~Graph();

private:	
	int	m_V;
	int	m_E;
	Edge*	m_pEdgeList;


}

Graph::Graph(const int V, const int E) :
	m_V(V), m_E(E), m_pEdgeList(new Edge[m_E])
{
}

Graph::~Graph() :
{
	delete [] m_pEdgeList;
}

// Driver program to test above functions
int main()
{
    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    const int V = 4;  // Number of vertices in graph
    const int E = 5;  // Number of edges in graph
    Graph graph(V, E);
 
 
    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;
 
    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;
 
    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;
 
    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;
 
    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;
 
    KruskalMST(graph);
 
    return 0;
}
