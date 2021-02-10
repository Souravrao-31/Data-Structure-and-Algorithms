/**
 * 
 * @description: Maximum edges that can be added to DAG so that is remains DAG
 * 
 * @author: Lakshya Khera
 * TODO!!!
 * 
 * */


#include<iostream>
#include "Graph.h"
using namespace std;

vector<int> Graph::topologicalSort() {
  vector<int> res;
  vector<int> inDegree(V,0);
  queue<int> q;
  for(int i =0;i<V;i++) {
    for(int v : adj[i]) {
      inDegree[v]++;
    }
  }
  for(int i =0;i<V;i++) {
    if(inDegree[i] == 0) q.push(i);
  }

  while(!q.empty()) {
    int t = q.front();
    q.pop();
    res.push_back(t);
    for(int i : adj[t]) {
      if(--inDegree[i] == 0) q.push(i);
    }
  }
  return res;
}

void Graph::maximumEdgeAddtion() {
  vector<bool> visit(V,false);
  vector<int> temp = topologicalSort();

  for(int i=0;i<temp.size();i++) {
    int t = temp[i];

    for(int m: adj[t]) {
      visit[m] = true;
    }

    for(int m =i+1;m<V;m++) {
      if(!visit[temp[m]]) {
        cout << t << " - " << temp[m]<<" ";
      }
      visit[temp[m]] = false; 
    }
    cout <<endl;
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
  g.maximumEdgeAddtion();
  return 0;
}