#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<vector<int>> &adj,int u, int v) {
  adj[v].push_back(v);
  adj[u].push_back(v);
}
void printGraph(vector<vector<int>> adj , int N) {
  cout << adj.size()<<endl;
  for(int i =0;i<N;i++ ){
    cout << "\n Adjacency list of vertex "<< i << "\n head ";   
    cout <<"->" << " ";
    for(int j : adj[i]) {
      cout << "-> " << j; 
    }
    cout << endl;

    }
}

int main() {
  int N = 4;
  vector<vector<int>> adj(N, {});
  addEdge(adj,0,1);
  addEdge(adj,0,3);
  addEdge(adj,1,3);
  printGraph(adj,N);

  return 0;
}