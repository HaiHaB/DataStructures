#include <iostream>
#include <list>
using namespace std;
/* Basic breadth first traversal for graph*/

class Graph
{
public:
	Graph(const int V);
	void AddEdge(const int u, const int v);
	void DFS(const int i);
	void DFSHelper(const int i, bool *visited);
	~Graph();

private:
	int		m_V;		// The number of vertex;
	list<int>	*m_pAdj;	// The adjacent list;

};

Graph::Graph(const int V) :
	m_V(V),
	m_pAdj(new list<int>[V])
{
}


void Graph::AddEdge(const int u, const int v)
{
	m_pAdj[u].push_back(v);
	m_pAdj[v].push_back(u);
}


void Graph::DFS(const int i)
{
	if ((i < 0) || (i >= m_V))
	{
		cout << "invalid input: " << i << endl;
		return;
	}

	bool *visited = new bool [m_V];
	for (int i = 0; i < m_V; ++i)
		visited[i] = false;
	
	DFSHelper(i, visited);

	cout << endl;
}

void Graph::DFSHelper(const int i, bool *visited)
{
	if (!visited[i])
	{
		cout << i << " ";
		visited[i] = true;
		
		for (int a : m_pAdj[i])
			DFSHelper(a, visited);
	}
}

Graph::~Graph()
{
	delete[] m_pAdj;
}

int main ()
{
 // Create a graph given in the above diagram
    Graph g(7);
    g.AddEdge(0, 1);
    g.AddEdge(0, 5);
    g.AddEdge(0, 6);
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);
    g.AddEdge(3, 4);
 
    cout << "Depth First Traversal from vertex 0\n";
    g.DFS(0);

    cout << "Depth First Traversal from vertex 2\n";
    g.DFS(2);

    cout << "Depth First Traversal from vertex 5\n";
    g.DFS(5);
 
    cout << "Depth First Traversal from vertex 7\n";
    g.DFS(7);

    return 0;
}

