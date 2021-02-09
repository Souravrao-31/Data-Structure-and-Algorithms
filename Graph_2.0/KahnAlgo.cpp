/**
 * 
 * @description: Kahn algorithm for topological sorting
 * 
 * @author: Lakshya Khera
 * 
 * 
 * */

#include<iostream>
#include "Graph.h"
using namespace std;

void Graph::TopologicalSort() {
  vector<int> inDegree(V,0);
  queue<int> q;


  for(int u = 0;u<V;u++) {
    for(int i : adj[u]) {
      inDegree[i]++;
    }
  }
  for(int u = 0;u<V;u++) {
    
    if(inDegree[u] == 0) q.push(u);
  }


  vector<int> res;
  while(!q.empty()) {
    int u  = q.front();
    q.pop();
    res.push_back(u);
    for(int m: adj[u]) {
      if(--inDegree[m] == 0 ) {
        q.push(m);
      }
    }
  }

  for(int i=0;i<V;i++) {
    cout << res[i]<<" ";
  }
  cout << endl;

 
}

int main() {

  Graph g(6); 
  g.addEdge(5, 2); 
  g.addEdge(5, 0); 
  g.addEdge(4, 0); 
  g.addEdge(4, 1); 
  g.addEdge(2, 3); 
  g.addEdge(3, 1); 
  g.TopologicalSort();

  return 0;
}