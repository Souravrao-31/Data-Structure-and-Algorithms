/*
# used to find first shortest path between all pairs of vertices.(in directed and undirected)
# Will work even if negative edges are present
# will also be able to detect negative cycles.
# Time complexity - O(V^3)
# Space Complexity - O(V^2)

*/

/*
The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem.
 The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph.

Floyd Warshall Algorithm
We initialize the solution matrix same as the input graph matrix as a first step. 
Then we update the solution matrix by considering all vertices as an intermediate vertex.
 The idea is to one by one pick all vertices and updates all shortest paths which include the picked vertex as an intermediate vertex in the shortest path. 
 When we pick vertex number k as an intermediate vertex, we already have considered vertices {0, 1, 2, .. k-1} as intermediate vertices. 
 For every pair (i, j) of the source and destination vertices respectively, there are two possible cases.
1) k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is.
2) k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as dist[i][k] + dist[k][j] if dist[i][j] > dist[i][k] + dist[k][j]
*/

#include<iostream>
#include<climits>
#include<vector>
using namespace std;

vector<int> Floyd_Warshall(int n, vector< vector<pair<int,int>> > &adj){
       vector<vector<int> > dist( n + 1, vector<int>(n+1,INT_MAX) );

       for(int i=1;i<=n; i++){ // O(V+ E)
           
           dist[i][i] = 0;
           
           for(pair<int,int> ed: adj[i]){
               int nb = ed.first;
               int w = ed.second;
               dist[i][nb] = w;
           }
       }
      
       for(int k=1;k<=n;k++){  // O(V^3)
           //kth place
           for(int i =1;i<= n;i++){
               for(int j=1;j<=n;j++){
                   dist[i][j] = min(dist[i][j], dist[i][k], + dist[k][j]);
               }
           }
       }

     return dist;
}

/*
4 10
1 2 3 
2 1 3
1 3 5
3 1 5
2 3 1
3 2 1
3 4 2
4 3 2
2 4 1
4 2 1
*/
int main(){

    int n,m; cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
       int from,to,weight;
       cin>>from>>to>>weight;
       edges.push_back({from,to,weight});
    }

    vector<vector<int>> dis=Floyd_Warshall(n,edges);
    for(int i=1;i<= n; i++){
       //cout<<"dis from src to "<<i<<" is "<<dis[i]<<'\n';
       for(int j=1;j<=n;j++){
           cout<<dis[i][j]<<" ";
       }
       cout<<endl;
    }

    return 0;
}
