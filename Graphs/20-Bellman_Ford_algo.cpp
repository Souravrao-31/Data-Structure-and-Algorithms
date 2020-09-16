/*
single source shortest path algorithm
Also handles negative weight edges
better than Dijkstra 
Directed and undirected 
*/

// Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph. The graph may contain negative weight edges.
// We have discussed Dijkstra’s algorithm for this problem. 
// Dijkstra’s algorithm is a Greedy algorithm and time complexity is O(VLogV) (with the use of Fibonacci heap).
// Dijkstra doesn’t work for Graphs with negative weight edges, Bellman-Ford works for such graphs.
// Bellman-Ford is also simpler than Dijkstra and suites well for distributed systems.
// But time complexity of Bellman-Ford is O(VE), which is more than Dijkstra.

/*
Algorithm
Following are the detailed steps.

Input: Graph and a source vertex src
Output: Shortest distance to all vertices from src. If there is a negative weight cycle, then shortest distances are not calculated, negative weight cycle is reported.

1) This step initializes distances from the source to all vertices as infinite and distance to the source itself as 0. Create an array dist[] of size |V| with all values as infinite except dist[src] where src is source vertex.

2) This step calculates shortest distances. Do following |V|-1 times where |V| is the number of vertices in given graph.
…..a) Do following for each edge u-v
………………If dist[v] > dist[u] + weight of edge uv, then update dist[v]
………………….dist[v] = dist[u] + weight of edge uv


3) This step reports if there is a negative weight cycle in graph. Do following for each edge u-v
……If dist[v] > dist[u] + weight of edge uv, then “Graph contains negative weight cycle”
The idea of step 3 is, step 2 guarantees the shortest distances if the graph doesn’t contain a negative weight cycle. 
If we iterate through all edges one more time and get a shorter path for any vertex, then there is a negative weight cycle


*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

//O(VE)
vector<int> Bellman_ford(int n,int src, vector<vector<int>> edges){
    vector<int> dis(n+1,INT_MAX);
    dis[src] = 0;

    //Relax all the edges n-1 times

    for(int i=0;i<n-1;i++){
        for(auto x:edges){
          int from = x[0], to = x[1], weight = x[2];
          if(dis[from] != INT_MAX &&  dis[to] > dis[from] + weight ){ //to avoid overflow
              //relaxed the edge
              dis[to] = dis[from] + weight;
          }
        }
    }
    // Lets check for negative weight cycle
    for(auto x: edges){
       int from = x[0], to=x[1], weight = x[2];
       if(dis[from] != INT_MAX && dis[to] > dis[from] + weight){
          cout<<"Negative Weight Cycle ";
          exit(0);
       }
    }
    
    return dis;

}
/*
3 3
1 2 4
1 3 5
3 2 -7
dis from src to 1 is 0
dis from src to 2 is -2
dis from src to 3 is 5



5 8
1 2 -1
1 3 4
2 3 3
2 4 2
2 5 2
4 2 1
4 3 5
5 4 -3
dis from src to 1 is 0
dis from src to 2 is -1
dis from src to 3 is 2
dis from src to 4 is -2
dis from src to 5 is 1



3 3
2 1 -4
1 3 5
3 2 -7
Negative Weight Cycle

*/
int main(){

    int n,m; cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
       int from,to,weight;
       cin>>from>>to>>weight;
       edges.push_back({from,to,weight});
    }

    vector<int> dis=Bellman_ford(n,1,edges);
    for(int i=1;i<= n; i++){
       cout<<"dis from src to "<<i<<" is "<<dis[i]<<'\n';
    }

    return 0;
}