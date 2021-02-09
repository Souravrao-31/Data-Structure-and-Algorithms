/**
 * Alien Dictionary 
 * https://practice.geeksforgeeks.org/problems/alien-dictionary/1
 * 
 * */
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
            ((*this->edges)[u]).push_back(v);
        }
        string topSort() {
            vector<int> res;
            queue<int> q;
            vector<int> inDegree(V);
            vector<bool> visited(V,false);
            for(int u=0;u<V;u++) {
                for(int v : (*this->edges)[u]) {
                    inDegree[v]++;
                }
            }
            for(int i=0;i<V;i++) {
                if(inDegree[i] == 0) {
                    q.push(i);
                }
            }
            while(!q.empty()) {
                int u = q.front();
                visited[u] = true;
                res.push_back(u);
                q.pop();
                for(int v : (*this->edges)[u]) {
                    if(!visited[v]) {
                       if(--inDegree[v]==0 ) {
                            q.push(v);
                        }  
                    }
                    
                }
            }
            string result ="";
            for(int i : res) {
                result+=('a'+i);
            }
            return result;
        }
};




string findOrder(string dict[], int N, int K) {
    
    Graph g(K);
    for(int i =1;i<N;i++) {
        string word1 = dict[i-1];
        string word2 = dict[i];
        for(int j =0;j<min(word1.size(),word2.size());j++) {
            if(word1[j] !=word2[j]) {
                g.addEdge(word1[j]-'a',word2[j]-'a');
                break;
            }
            
        }
    }
    return g.topSort();

}