#include<iostream>
#include "Graph.h"
using namespace std;



void Graph::DFS(int s, vector<bool> &visits) {

  visits[s] = true;
  for(int i : adj[s]) {
    if(!visits[i]) DFS(i, visits);
  }
}

int Graph::findMotherVertex() {
  vector<bool> visit(V, false);
  int v;
  for(int i =0;i<V;i++) {
    if(!visit[i]) {
      DFS(i,visit);
      v = i;
    }
    
  }
  return v;
}




int main() {
  int N = 7;
  Graph g (7);
  g.addEdge(0, 1); 
  g.addEdge(0, 2); 
  g.addEdge(1, 3); 
  g.addEdge(4, 1); 
  g.addEdge(6, 4); 
  g.addEdge(5, 6); 
  g.addEdge(5, 2); 
  g.addEdge(6, 0); 
  cout << g.findMotherVertex()<<endl;
  return 0;
}