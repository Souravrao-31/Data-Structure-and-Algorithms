#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include "Graph.h"
using namespace std;



void Graph::BFS(int s) {
  if(s >= this->V) return;
  vector<bool> visited (this->V, false);
  queue<int> q;
  q.push(s);
  while(!q.empty()) {
    int curr = q.front();
    visited[curr] = true;
    q.pop();
    cout << curr<<" ";
    for(int i : adj[curr]) {
      if(!visited[i]) q.push(i);
    }
  }
}

int main() {
  Graph myGraph(4);
  myGraph.addEdge(0,2);
  myGraph.addEdge(0,1);
  myGraph.addEdge(1,2);
  myGraph.addEdge(2,3);
  myGraph.addEdge(3,3);
  myGraph.BFS(0);
  return 0;
}