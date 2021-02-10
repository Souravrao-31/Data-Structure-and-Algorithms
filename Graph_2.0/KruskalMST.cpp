/**
 * 
 * @description: Kruskal Minimum Spanning Tree algo, uses Union find algo to keep graph acyclic
 * 
 * @author: Lakshya Khera
 * 
 * */

#include<iostream>
#include<algorithm>
#include "WeightedGraph.h"
using namespace std;


struct Edge {
  int src;
  int dest;
  int weight;
};

bool compare(const Edge&a , const Edge&b) {
  return a.weight< b.weight;
}


int findParent(vector<pair<int,int>> &subsets, int x) {
  if(subsets[x].first== -1) return x;
  return findParent(subsets,subsets[x].first);
}

void unionSet(vector<pair<int,int>> &subsets, int x,int y ) {
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

void WeightedGraph::findMST() {
  vector<Edge> edges;// Need sort edges according to weight
  vector<Edge> res; // Need array to sort
  vector<pair<int,int>> subsets(V, pair<int,int>(-1, 0)); // Need to keep in check parent and rank for union find algo

  for(int i =0;i<V;i++) {
    for(int j=0;j<V;j++) {
      if((*graph)[i][j] !=-1) {
        Edge e;
        e.src = i;
        e.dest = j;
        e.weight = (*graph)[i][j];
        edges.push_back(e);
      }
    }
  }
  
  sort(edges.begin(),edges.end(),compare);
  // for(int i =0;i<edges.size();i++) {
  //   cout<< edges[i].src << " -- > " << edges[i].dest << endl;
  // }
  for(int i =0;i<edges.size();i++) {
    Edge smallest_edge = edges[i];

    int parentX = findParent(subsets,smallest_edge.src);
    int parentY = findParent(subsets,smallest_edge.dest);
    if(parentX!=parentY) {
      res.push_back(smallest_edge);
      unionSet(subsets,parentX,parentY);
    }
  }

  //TODO: Print MST!
  for (int i = 0; i < res.size(); ++i) {
    cout<<res[i].src<<" -- "<<res[i].dest<<" == "<<res[i].weight<<endl;  
  }
  return; 
}

int main() {
  WeightedGraph g(4);
  g.addEge(0,1,10);
  g.addEge(0,2,6);
  g.addEge(0,3,5);
  g.addEge(1,3,15);
  g.addEge(2,3,4);
  g.findMST();
  return 0;
}