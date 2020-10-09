/**
 * 
 * @description: Weighted Graph header file
 * 
 * @author: Lakshya Khera
 * 
 * */

#include<iostream>
#include<vector>
using namespace std;
class WeightedGraph {
  private:
    int V;
    vector<vector<int>> *graph;

  public:
    WeightedGraph(int V);
    void addEge(int u,int v, int weight);
    void findMST();
};


WeightedGraph::WeightedGraph(int V) {
  this->V = V;
  this->graph = new vector<vector<int>>(V,vector<int>(V,-1));
}

void WeightedGraph::addEge(int u,int v,int weight) {
  if(u>=V || v>=V || u<0 || v <0 ) throw "Value of vertices are invalid";
  (*graph)[u][v] = weight;
}

