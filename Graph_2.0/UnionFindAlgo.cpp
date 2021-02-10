/**
 * 
 * @description: Union find algorithm, an aglorithm which used disjoints set data structure to find whether graph contains cycle or not
 * 
 * @author: Lakshya Khera 
 * */


#include<iostream>
#include"Graph.h"


int findParent(vector<int> &disjointSets, int x) {
  if(disjointSets[x] == -1) return x;
  return findParent(disjointSets,disjointSets[x]);
}

void unionSet(vector<int> &disjointSets, int x,int y) {
  int xSet = findParent(disjointSets, x);
  int ySet = findParent(disjointSets,y);
  if(xSet!=ySet) {
    disjointSets[ySet] = xSet;
  }
}
using namespace std;
bool Graph::detectCycle() {
  vector<int> disjointSets(V,-1);
  for(int i =0;i<V;i++) {
    for(int v : adj[i]) {
      int parentX = findParent(disjointSets,i);
      int parentY = findParent(disjointSets, v);
      if(parentX == parentY) return true;
      unionSet(disjointSets, i, v);
    }
  }
  return false;
}

int main() {
  Graph g(3);
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(2,0);
  cout << g.detectCycle() <<endl;
  return 0;
}