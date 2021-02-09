/**
 * 
 * @description: Cycle detection in a directed graph, using DFS
 * 
 * 
 * @author Lakshya Khera
 * 
 * 
 * 
 * 
 * */

#include<iostream>
#include "Graph.h"
using namespace std;


bool Graph::detectCycleHelper(int s, vector<bool> &visits, vector<bool> &recurStack) {
  if(!visits[s]) {
    visits[s] = true;
    recurStack[s] = true;
    for(int i : adj[s]) {
      if(!visits[s] && detectCycleHelper(i,visits,recurStack)) {
        return true;
      }else if(recurStack[i]) {
        return true;
      }
    }
  }
  recurStack[s] = false;
  return false;
}

bool Graph::detectCycle() {
  vector<bool> visited(V,false);
  vector<bool> recurStack(V,false);

  for(int i=0;i<V;i++) {
    if(detectCycleHelper(i, visited,recurStack)) return true;
  }
  return false;
}
int main() {

  Graph g(4); 
  g.addEdge(0, 1); 
  g.addEdge(0, 2); 
  g.addEdge(1, 2); 
  g.addEdge(2, 0); 
  g.addEdge(2, 3); 
  g.addEdge(3, 3); 
  cout << g.detectCycle()<<endl;
  return 0;
}