#include<bits/stdc++.h>
using namespace std;

class Graph{

    list<int> *l;
    int V;
public:
    Graph(int V){
    this->V = V;
    l = new list<int> [V];
    }    

    void AddEdge(int x,int y){
       //directed graph
       l[x].push_back(y);
    }

    void topological_sort(){
        //indegree
        int *indegree = new int [V];
        // 0 indegree
        for(int i=0;i<V;i++){
            indegree[i] = 0;
        }

        //update indegree by traversing edges x->y
       // indegree [y]++
       for(int i=0;i<V;i++){
          
           for(auto y:l[i]){
              indegree[y]++;
           }
       }

       //bfs
       queue<int> q;
       //1. step find nodes with 0 indegree
       for(int i=0;i<V;i++){
          if(indegree[i] == 0){
              q.push(i);
          }
       }
        //start removing elements from the queue 
        while(!q.empty()){
            int node = q.front();
            cout<<node<<" ";
            q.pop();

            //iterate over nbrs of that and reduce their indegree by 1
            for(auto nbr:l[node]){
                indegree[nbr]-- ;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }

    }
};

int main(){

    Graph g(6);
    g.AddEdge(0,2);
    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(2,5);
    g.AddEdge(4,5);
    g.AddEdge(3,5);

    g.topological_sort();
    return 0;
}