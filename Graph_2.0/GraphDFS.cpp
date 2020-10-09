#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include "Graph.h"
using namespace std;



void Graph::DFS(int s, vector<bool> &visited ) {
  if(s>=V) {
    return;
  }
  if(visited[s]) return;
  visited[s] = true;
  cout << s << " ";
  for(int i : adj[s]) {
    DFS(i, visited);
  }
}

int main() {
  int V = 4;
  Graph myGraph(V);
  myGraph.addEdge(0,2);
  myGraph.addEdge(0,1);
  myGraph.addEdge(1,2);
  myGraph.addEdge(2,3);
  myGraph.addEdge(3,3);
  vector<bool> visit(V, false);
  myGraph.DFS(0, visit);
  return 0;
}