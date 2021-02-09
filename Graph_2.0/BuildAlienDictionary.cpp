#include<iostream>
#include<vector>
using namespace std;


class Graph {
  public:
    vector<vector<int>> *edges;
    int V;
    Graph(int V) {
        this->V = V;
        edges = new vector<vector<int>>(V);
    }
    void addEdge(int u,int v) {
        cout << u << " "<<v<<endl;
        ((*this->edges)[u]).push_back(v);
    }
    
};

string findOrder(string dict[], int N, int K) {
    
    Graph g(K);
    for(int i =1;i<N;i++) {
        string word1 = dict[i-1];
        string word2 = dict[i];
        for(int j =0;j<min(word1.size(),word2.size());j++) {
            g.addEdge(word1[j]-'a',word2[j]-'a');
        }
    }
    return "vbnm";

}

int main() {
  string dict[3]={"fdsf","fdsf","fdsf"};
  findOrder(dict,3,4);

  return 0;
}