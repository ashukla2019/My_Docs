#include <iostream>
#include <list>
using namespace std;

class Graph 
{
	int numVertices;
	list<int> *adjLists;
	bool *visited;
 public:
	Graph(int V);
	void addEdge(int u, int v);
	void dfs(int vertex);
};
Graph::Graph(int vertices)
{
	numVertices = vertices;
	adjLists = new list<int>[vertices];
	visited = new bool[vertices];
}
void Graph::addEdge(int u, int v)
{
	adjLists[u].push_front(v);
}
void Graph::DFS(int vertex) 
{
	visited[vertex] = true;
	list<int> adjList = adjLists[vertex];
	cout << vertex << " ";
	list<int>::iterator i;
	for (i = adjList.begin(); i != adjList.end(); ++i)
	{
		if (!visited[*i])
		{
			dfs(*i);
		}
}

int main()
{
  // create a graph 
    Graph g(5); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(0, 3);
    g.addEdge(1, 2); 
    g.addEdge(2, 4);
    g.addEdge(3, 3); 
    g.addEdge(4, 4);
  cout<<"Depth First Search from vertex 2 is :"<<endl; 
  g.DFS(0);

  return 0;
}
