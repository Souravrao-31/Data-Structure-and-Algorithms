/**
 * 
 * @description: Finding all topological sort using backtracking and Kahn algorithm
 * 
 * @author: Lakshya Khera
 *  
 * */



#include<iostream>
using namespace std;
#include "Graph.h"


void Graph::allTopologicalSort() {
  vector<bool> visited(V,false);
  vector<int> inDegree(V,0);
  for(int i =0;i<V;i++) {
    for(int j : adj[i]) {
      inDegree[j]++;
    }
  }

  vector<int> res; 
  allTopologicalSortUtil(res,inDegree, visited);
}

void Graph::allTopologicalSortUtil(vector<int> &res, vector<int> &inDegree, vector<bool> &visited) {
  bool flag  = false;

  for(int i =0;i<V;i++) {
    if(inDegree[i] == 0  &&!visited[i]) {
      for(int j : adj[i]) {
        inDegree[j]--;
      }
      res.push_back(i);
      visited[i] = true;
      allTopologicalSortUtil(res,inDegree,visited);

      //BACKTRACK <3

      visited[i] = false;
      res.erase(res.end()-1);
      for(int j : adj[i]) {
        inDegree[j]++;
      }
      flag = true;
    }
  }
  if(!flag) {
    for (int i = 0; i < res.size(); i++) 
            cout << res[i] << " "; 
    cout << endl; 
  }
}


int main() {

  Graph g(6); 
  g.addEdge(5, 2); 
  g.addEdge(5, 0); 
  g.addEdge(4, 0); 
  g.addEdge(4, 1); 
  g.addEdge(2, 3); 
  g.addEdge(3, 1); 
  
  cout << "All Topological sorts\n"; 
  
  g.allTopologicalSort(); 
  return 0;
}