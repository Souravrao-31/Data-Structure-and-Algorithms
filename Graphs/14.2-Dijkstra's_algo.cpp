#include<bits/stdc++.h>
using namespace std;



/*
Given a graph consisting 'N' nodes (labeled 1 to N) where a specific given node 'S' represents the starting position and an edge between two nodes is of a given length, which may or may not be equal to other lengths in the graph.

It is required to calculate the shortest distance from the start position (Node 'S') to all of the other nodes in the graph.

If a node is unreachable, the distance is assumed as -1.

Input Format
The first line contains T, denoting the number of test cases. First line of each test case has two integers N, M denoting the number of nodes in the graph and, denoting the number of edges in the graph.

The next M lines each consist of three space-separated integers x,y,r where x and y denote the two nodes between which the undirected edge exists, 'r' denotes the length of edge between these corresponding nodes.

The last line has an integer, 'S' denoting the starting position.

1
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1

o/p - 24 3 15 
*/
class Graph
{
	int numEdges; //number of edges
	int numVertices; // number of vertices
	unordered_map < int, list< pair<int, int> > > adjList; // adjacency list

	
public:
Graph(int e, int v)
	{
		numEdges = e;
		numVertices = v;
	}
	void AddEdges(int edge1, int edge2, int distance) //we assume it is a bidirectional graph
	{
		adjList[edge1].push_back(make_pair(edge2, distance));
		adjList[edge2].push_back(make_pair(edge1, distance));
	}

	void callDjikstra(int source)
	{
		unordered_map <int, int > distance;
		
		for (auto node : adjList)
		{
			distance[node.first] = INT_MAX; // for every node in the adjacency list we set(assume) the distance from source as infinity
		}
		distance[source] = 0; //we set the distance of the source from itself to zero

		set <pair<int, int>> minCheck; //first one is the distance, second one is the node. Why ? Because in set the sorting is based on first parameter
		
		minCheck.insert({0, source}); // we insert the source node and its distance from the source into the set

		//we need to go on finding the node at minimum distance from source till the set becomes empty. so we create a while loop
		while (!minCheck.empty())
		{
			pair<int, int > node_pair = *(minCheck.begin()); // minCheck.begin() returns a pointer to the first element of the set, so using * we get the value of the first element in the set
			
			int node = node_pair.second; // the node which is at minimum distance from source
			int nodeDistance = node_pair.first; //the distance of the node from the source

			minCheck.erase(minCheck.begin()); //since we are trying to simulate a queue and we are done with the value so we pop it.

			//iterate over to find the adjacent neighbors and update their distances
			for (auto neighbor_pair : adjList[node])
			{
				if (nodeDistance + neighbor_pair.second < distance[neighbor_pair.first])
				{
					//update the distance of the node => delete from set and insert in it.
					//update it in distance, update it in minCheck as well.
					int adjNode = neighbor_pair.first;
					
					auto finder = minCheck.find(make_pair(distance[adjNode], adjNode));
					if (finder != minCheck.end())
					{
						minCheck.erase(finder);
					}
					distance[adjNode] = nodeDistance + neighbor_pair.second;
					minCheck.insert(make_pair(distance[adjNode], adjNode));
				}
			}
		}
        	for (int i=1;i<=numVertices;i++)
			{    if(i==source)
			       continue;
				if (distance.count(i)==0 || distance[i]==INT_MAX)
					cout<<-1<<" ";
				else
                cout << distance[i] << " ";
			}
	}
	void displayEdges()
	{
		for (auto L : adjList)
		{
			cout << L.first << " ---> ";
			for (auto p : adjList[L.first])
			{
				cout <<"(" << p.first << "," << p.second << ")";
			}
			cout << endl;
		}
	}

};

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		
		int vertices, edges, source;
		cin >> vertices >> edges;
		Graph g(edges, vertices);

		for (int i = 0; i < edges; i++)
		{
			int edge1, edge2, dist;
			cin >> edge1 >> edge2 >> dist;
			g.AddEdges(edge1, edge2, dist);

		}
		cin >> source;
		g.callDjikstra(source);
		//g.displayEdges();
        cout << endl;
	}
}
