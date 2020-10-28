// STL implementation of Dijisktra's Algorithm
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f//this is your definition of infinity

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph//all this is just a simple creation of graph, and and can be done easily using vectors so not necessary
{
	int V; // No. of vertices

	// In a weighted graph, we need to store vertex
	// and weight pair for every edge
	list< pair<int, int> > *adj;

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v, int w);

	// Print MST using Prim's algorithm
	void primMST();
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w)
{
	adj[u].push_back(make_pair(v, w));
	adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::dijisktra()//real algorithm starts from here
{
	// Create a priority queue to store vertices that
	
	
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq;//this is simply a syntax for priority queue , now here it takes 3 arguments,
	//first is type of data, which is pair here, next is container type, which is vector by default, so let it be,next is the function used for
	//comparing. Now by default, it is lesser function i.e by default,a priority queue pops out the largest element.By using greater function,
	//you allow the least value to be popped out of a priority queue.

	int src = 0; // Taking vertex 0 as source

	// Create a vector for keys and initialize all
	// keys as infinite (INF)
	vector<int> key(V, INF);//key array

	// To store parent array which in turn store path in dijisktra's algorithm
	vector<int> parent(V, -1);//to store which vertex has what parent?

	// To keep track of vertices included in dijisktra's
	vector<bool> inMST(V, false);//marked array

	// Insert source itself in priority queue and initialize
	// its key as 0.
	pq.push(make_pair(0, src));//make_pair is a function that returns a pair
	key[src] = 0;

	/* Looping till priority queue becomes empty */
	while (!pq.empty())
	{
		// The first vertex in pair is the minimum key
		// vertex, extract it from priority queue.
		// vertex label is stored in second of pair (it
		// has to be done this way to keep the vertices
		// sorted key (key must be first item
		// in pair)
		int u = pq.top().second;
		pq.pop();
		
		if(inMST[u]) // If already included, discard
		   continue;

		inMST[u] = true; // Include vertex in MST

		// 'i' is used to get all adjacent vertices of a vertex
		list< pair<int, int> >::iterator i;
		
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			// Get vertex label and weight of current adjacent
			// of u.
			int v = (*i).first;
			int weight = (*i).second;

			// If v is not in MST and weight of (u,v)+ key[u] is smaller
			// than current key of v
			if (inMST[v] == false && key[v] > key[u]+weight)
			{
				// Updating key of v
				key[v] = weight+key[u];
				pq.push(make_pair(key[v], v));
				parent[v] = u;
			}
		}
	}

	// Print shortest/lightest path from u to each vertex
	for (int i = 1; i < V; ++i)
		printf("%d - %d\n", i, key[i]);
}

// Driver program to test methods of graph class
int main()
{
	// create the graph given in above fugure
	int V = 9;
	Graph g(V);

	// making above shown graph
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	g.dijisktra();

	return 0;
}
