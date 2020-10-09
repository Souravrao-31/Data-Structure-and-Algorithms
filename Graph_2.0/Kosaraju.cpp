#include<iostream>
#include "Graph.h"
using namespace std;

vector<vector<int> > Graph::findSCC() {
  stack <int> st;
  vector<bool> visit(V,false);

  //TODO: Do DFS and maitain stack and visited set
  DFS(0, st, visit);
  //TODO: Reverse Graph
  this->adj = reverseGraph();
  //TODO: Do DFS and get vector<vector<int>>
  for(int i =0;i<visit.size(); i++ ){
    visit[i] = false
  }
  vector<vector<int>> res;
  getSCC(res,st,visit);
  return res;
}

void Graph::DFS(int s, stack<int> &st, vector<bool> &visits) {

  visits[s] = true;
  for(int i : adj[s]) {
    if(!visits[i]) DFS(i, st, visits);
  }
  st.push(s);
}
void Graph::DFS(int s , vector<bool> &visits,vector<int> &curr) {
  visits[s] = true;
  for(int i : adj[s]) {
    if(!visits[i]) {
      curr.push_back(i);
      DFS(i,visits, curr);
    }
  }
}


list<int> * Graph::reverseGraph() {
  list<int> *newadj = new list<int>[V];
  for(int i =0;i<V;i++) {
    for(int j : adj[i]) {
      newadj[j].push_back(i);
    }
  }
  return newadj;
}

void Graph::getSCC(vector<vector<int>> &res,stack<int> &st , vector<bool> &visits) {
  while(!st.empty()) {
    int s = st.top();
    st.pop();
    vector<int> curr;
    if(!visits[s]) {
      curr.push_back(s);
      DFS(s,visits,curr);
    }
    res.push_back(curr);
  }
}


int main() {
  int N = 7;
  Graph graph(7);
  graph.addEdge(0, 1);
  graph.addEdge(1, 2);
  graph.addEdge(2, 0);
  graph.addEdge(1, 3);
  graph.addEdge(3, 4);
  graph.addEdge(4, 5);
  graph.addEdge(5, 3);
  graph.addEdge(5, 6);
  vector<vector<int> > result = graph.findSCC();
  for(int i =0;i<result.size();i++) {
    for(int j : result[i]) {
      cout << j << " " ;
    }
    cout <<endl;
  }
  return 0;
}