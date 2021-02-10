/**
 * 
 * 
 * @description: Topological sorting, means printing vertex before it's childs or adj vertices!
 * 
 * @author: Lakshya Khera
 * 
 * 
 * 
 * */


#include<iostream>
#include"Graph.h"
using namespace std;


void Graph::TopologicalSort() {
  stack<int> st;
  vector<bool> visit(V,false);

  for(int i =0;i<V;i++) {
    if(!visit[i]) {
      visit[i] = true;
      TopologicalSortUtil(i,st,visit);
    }
  }
  while(!st.empty()) {
    int t = st.top();
    st.pop();
    cout << t << " ";
  }
  cout <<endl;
}
 
void Graph::TopologicalSortUtil(int s,stack<int> &st, vector<bool> &visits) {
  st.push(s);
  for(int i : adj[s]) {
    if(!visits[i]) {
      visits[i] = true;
      TopologicalSortUtil(i,st,visits);
    }
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
  g.TopologicalSort();
  return 0;
}