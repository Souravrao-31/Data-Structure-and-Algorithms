/**
 * 
 * @description: Union find algorithm using rank and path compression method
 * 
 * @author: Lakshya Khera
 * 
 * */



#include<iostream>
#include "Graph.h"
using namespace std;


int findParent(vector<pair<int,int>> &subsets, int x) {
  if(subsets[x].first== -1) return x;
  return findParent(subsets,subsets[x].first);
}

void unionSet(vector<pair<int,int>> &subsets, int x, int y) {
  int xroot = findParent(subsets, x); 
  int yroot = findParent(subsets, y); 
  
  // Attach smaller rank tree under root of high rank tree 
  // (Union by Rank) 
  if (subsets[xroot].second < subsets[yroot].second) 
    subsets[xroot].first = yroot; 
  else if (subsets[xroot].second > subsets[yroot].second) 
    subsets[yroot].first = xroot; 
  
  // If ranks are same, then make one as root and increment 
  // its rank by one 
  else { 
    subsets[yroot].first = xroot; 
    subsets[xroot].second++; 
  } 
}

bool Graph::detectCycle() {
  vector<pair<int,int>> subsets(V, pair<int,int>(-1, 0));
  for(int i =0;i<V;i++) {
    for(int v : adj[i]) {
      int parentX = findParent(subsets,i);
      int parentY = findParent(subsets,v);
      if(parentX == parentY) return true;
      unionSet(subsets,i,v);
    }
  }
  return false;

}

int main() {
  Graph g(3);
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(0,2);
  cout << g.detectCycle()<<endl;

  return 0;
}