// Adjascency List representation in C++

#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int vertex;
	list<int>*l;
	public:
		Graph(int v)
		{
			vertex = v;
			l = new list<int>[v];
		}
		void addEdge(int s, int d) 
		{
  			l[s].push_back(d);
  			l[d].push_back(s);
		}
		// Print the graph
		void printGraph() 
		{
  			for (int d = 0; d < vertex; ++d) 
  			{
    			cout << "\n Vertex "<< d << ":";
    			for (auto x : l[d])
    			{
      				cout << "-> " << x;
    				printf("\n");
  				}
			}
		}
};

int main() 
{
  int v = 5;
  Graph g(v);
  // Add edges
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);
  g.addEdge(1, 2);
  g.printGraph();
}
