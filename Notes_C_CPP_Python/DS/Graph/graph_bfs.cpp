#include<iostream>
#include <list> 
#include <queue>
using namespace std; 
   
// a directed graph class 
class Graph 
{ 
    int V;    // No. of vertices 
   
    // Pointer to an array containing adjacency lists 
    list<int>* adjList;    
public: 
    Graph(int V);  // Constructor 
   
    // add an edge from vertex v to w
    void addEdge(int v, int w);  
   
    // BFS traversal sequence starting with s 
    void BFS(int s);   
}; 
   
Graph::Graph(int V) 
{ 
    this->V = V; 
    adjList = new list<int>[V]; 
}
 void Graph::addEdge(int u, int v) 
{ 
    adjList[u].push_back(v); // Add v to u’s list. 
} 
   
void Graph::BFS(int s) 
{ 
    // initially none of the vertices is visited
    bool *visited = new bool[V]; 
    for(int i = 0; i<V; i++) 
	{
        visited[i] = false; 
	}
   
    // queue to hold BFS traversal sequence 
    queue<int> q; 
   
    // Mark the current node as visited and enqueue it 
    visited[s] = true; 
    q.push(s); 
   
    while(!q.empty()) 
    { 
        // dequeue the vertex 
        s = q.front(); 
        cout<<"node value:"<<s<<"\n"; 
        q.pop(); 
   
        // get all adjacent vertices of popped vertex and process each if not already visited 
        for (auto i= adjList[s].begin(); i != adjList[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                q.push(*i); 
            } 
        } 
    } 
}
// main program 
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
   
    cout<<"Breadth First Traversal for given graph (with 0 as starting node): "<<endl;
    g.BFS(0); 
   
    return 0; 
}
