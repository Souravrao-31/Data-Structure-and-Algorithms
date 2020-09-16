/*
Kosaraju's algorithm is a strongly connected graph

A directed graph is strongly connected if there is a path between all pairs of vertices. 
A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph. 
For example, there are 3 SCCs in the following graph.
   
   1 ---> 0  ------> 3
   ^    /            |
   |  /              |
  |  /               |
  2                  4


  We can find all strongly connected components in O(V+E) time using Kosaraju’s algorithm. Following is detailed Kosaraju’s algorithm.
1) Create an empty stack ‘S’ and do DFS traversal of a graph. In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, 
  push the vertex to stack. In the above graph, if we start DFS from vertex 0, we get vertices in stack as 1, 2, 4, 3, 0.
2) Reverse directions of all arcs to obtain the transpose graph.
3) One by one pop a vertex from S while S is not empty. Let the popped vertex be ‘v’. 
  Take v as source and do DFS (call DFSUtil(v)). The DFS starting from v prints strongly connected component of v. In the above example, we process vertices in order 0, 3, 4, 2, 1 (One by one popped from stack).


*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005, M = 22;
vector<int> gr[N], grr[N];
vector<int> order;
vector<int> in_comp[N];
int vis[N], comp[N];


void dfs_reverse(int cur,int col){
    comp[cur] = col;
    in_comp[col].pb(cur);
    vis[cur] = 1;
    for(auto x : grr[cur]){
       if(!vis[x]) dfs_reverse(x,col);
    }
}


void dfs(int cur){
    vis[cur] = 1;
       for(auto x : gr[cur]){
          if(!vis[x]) dfs(x);
       }
       order.pb(cur);
}

   // T(n) = O(n) 
void solve(){
    int i,j,k,n,m, ans=0, cnt=0, sum=0;
    cin>>n>>m;
    for(i =0;i<m;i++){
       int x,y;
       cin>>x>>y;
       gr[x].pb(y);
       grr[y].pb(x);
    }
    for(int i=1;i<=n;i++){
       if(!vis[i]) dfs(i);
    }
    memset(vis, 0 , sizeof(vis));
    int col = 1;
    for(i=n;i>=1;i--){
       if(!vis[order[i]] ) {
           dfs_reverse(order[i], col);
           col++;
       }
    }
     for(int i=1;i<=n;i++){
       cout<<i << "->"<<comp[i]<<'\n';
    }
}


/*
6 7 
1 2 
2 3 
3 1 
3 4 
4 5 
5 6 
6 4 

1->2
2->2
3->2
4->3
5->3
6->3
*/


int main()
{
    
    solve();
}