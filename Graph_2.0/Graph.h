#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<stack>
#include<set>
using namespace std;


class Graph {
  private:
    int V;
    list<int> *adj;
  public:
    
    Graph(int V);
    void addEdge(int u,int v);
    void BFS(int s);
    void DFS(int s , vector<bool> &visits);
    void DFS(int s, stack<int> &st , vector<bool> &visits);
    void DFS(int s , vector<bool> &visits,vector<int> &curr);
    bool detectCycleHelper(int s , vector<bool> &visits,vector<bool> &recurStac);
    void getSCC(vector<vector<int>> &res,stack<int> &st , vector<bool> &visits);
    int findMotherVertex();
    bool detectCycle();
    list<int> * reverseGraph();
    vector<vector<int> > findSCC();
    void TopologicalSort();
    vector<int> topologicalSort();
    void TopologicalSortUtil(int s,stack<int> &st, vector<bool> &visits);
    void maximumEdgeAddtion();
    void allTopologicalSort();
    void allTopologicalSortUtil(vector<int> &res, vector<int> &inDegree,vector<bool> &visited);
    void TransitiveClosure();
};


Graph::Graph(int V) {
  this->V = V;
  this->adj = new list<int>[V];

}

void Graph::addEdge(int u,int v) {
  this->adj[u].push_back(v);

}

