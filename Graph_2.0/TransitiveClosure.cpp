/**
 * 
 * @description: Finding transitive closure of a graph! 
 * @TimeComplexity => O(V**3)
 * 
 * 
 * @author: Lakshya Khera
 * 
 * 
 * */

#include<iostream>
#include "Graph.h"
using namespace std;

void Graph::TransitiveClosure() {
  vector<vector<int> > reach(V,vector<int> (V,0));
  for(int i =0;i<V;i++) {
    for(int j : adj[i]) {
      reach[i][j] = 1;
    }
  }

  for(int i =0;i<V;i++) {
    for(int j = 0;j<V;j++) {
      for(int k = 0;k<V;k++) {
        reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
      }
    }
  }


  for(int i =0;i<V;i++) {
    for(int j=0;j<V;j++) {
      cout << reach[i][j] << " ";
    }
    cout <<endl;
  }
}
int main() {
  Graph myGraph(4);
  myGraph.addEdge(0,1);
  myGraph.addEdge(0,0);
  myGraph.addEdge(0,3);
  myGraph.addEdge(1,1);
  myGraph.addEdge(1,2);
  myGraph.addEdge(2,2);
  myGraph.addEdge(2,3);
  myGraph.addEdge(3,3);
  myGraph.TransitiveClosure();
  return 0;
}
