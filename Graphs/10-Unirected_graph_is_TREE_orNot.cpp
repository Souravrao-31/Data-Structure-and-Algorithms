#include<bits/stdc++.h>
using namespace std;

/*
In undirected graph the edge(a,b) and (b,a) -> hence
if a graph has cycle it cannot be tree
in Is_tree function if we visit the vertex second time it means its cycle
it cannot be tree 
*/
class Graph{

    list<int> *l;
    int V;
public:
    Graph(int V){
    this->V = V;
    l = new list<int> [V];
    }    

    void AddEdge(int x,int y){
       l[x].push_back(y);
       l[y].push_back(x);
    }

    bool is_Tree(){
    
      bool *visited = new bool[V];
      int *parent   = new int[V];
      
      queue<int> q;
       for(int i=0;i<V;i++){
          visited[i] = false;
          parent[i] = i;
       }
       int src = 0;

       q.push(src);
       visited[src] = true;

       //pop out each node
       while(!q.empty()){
         int node = q.front();
         q.pop();

         for(int nbr: l[node]){
            if(visited[nbr]==true and parent[node] != nbr){
            return false;
            }
            else if(!visited[nbr]){
                 visited[nbr]= true;
                 parent[nbr]= node;
                 q.push(nbr);
            }
         }
          
       }

       return true;
    }
};

int main(){
    Graph g(4);
    g.AddEdge(0,1);
   // g.AddEdge(3,2);  //if u remove it will non cyclic
    g.AddEdge(1,2);
    g.AddEdge(0,3);

    if(g.is_Tree()){
          cout<<"Yes it is a Tree";
    }
    else cout<<"Not a Tree";
    return 0;
}