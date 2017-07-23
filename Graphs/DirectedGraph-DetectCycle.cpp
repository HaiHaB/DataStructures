#include <iostream>
#include <list>

using namespace std;
/* Basic breadth first traversal for graph*/

class Graph
{
public:
	Graph(const int V);
	~Graph();
	void AddEdge(const int u, const int v);
	bool isCyclic();

private:

	bool isCyclicHelper(const int i, bool visited[], bool restack[]);

	int		m_V;		// The number of vertex;
	list<int>	*m_pAdj;	// The adjacent list;

};

Graph::Graph(const int V) :
	m_V(V),
	m_pAdj(new list<int>[V])
{
}

Graph::~Graph()
{
	delete[] m_pAdj;
}

void Graph::AddEdge(const int u, const int v)
{
	m_pAdj[u].push_back(v);
}

bool Graph::isCyclic()
{
	bool *visited = new bool [m_V];
	bool *restack = new bool [m_V];
	for (int i = 0; i < m_V; ++i)
	{
		visited[i] = false;
		restack[i] = false;
	}

	for (int i = 0; i < m_V; ++i)
	{
		if(isCyclicHelper(i, visited, restack))
			return true;
	}
	
	return false;
}

bool Graph::isCyclicHelper(const int i, bool visited[], bool restack[])
{
	if(!visited[i])
	{
		visited[i] = true;
		restack[i] = true;

		for (int k : m_pAdj[i])
		{
			if ((!visited[k]) && isCyclicHelper(k, visited, restack))
				return true;
			else if (restack[k])
				return true;
		}
	}
	
	restack[i] = false;
	return false;
}
int main ()
{
 // Create a graph given in the above diagram
    Graph g(4);
    g.AddEdge(0, 1);
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);
    g.AddEdge(0, 3);
 
    cout << "TestCase 1 => should not be a cyclic graph: " << g.isCyclic() << endl;

    g.AddEdge(3, 0);

    cout << "TestCase 2 => should  be a cyclic graph: " << g.isCyclic() << endl;
 
    return 0;
}

