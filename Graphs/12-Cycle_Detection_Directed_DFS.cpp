#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list <int> *l;
public:
    Graph(int V){
       this->V = V;
       l = new list<int> [V];
    }
    //directed graph
   void AddEdge(int x,int y,bool directed = true){
       l[x].push_back(y);

       if(!directed){
           l[y].push_back(x);
       }
    }

    bool Cycle_helper(int node, bool *visited, bool *stack){
         
        visited[node] = true;
        stack[node]   = true;

        for(int nbr: l[node]){
        //two cases
        if(stack[nbr]==true) return true;
        else if(visited[nbr] == false){
            bool cycle_mila = Cycle_helper(nbr,visited,stack);
            if(cycle_mila==true){
                return true;
            }
        }
            
     }

        //leave a node
        stack[node] = false;
        return false;
    }

    bool Contains_Cycle(){
        //Check for cycle in directed graph
        bool *visited = new bool[V];
        bool *stack = new bool[V];
       
        for(int i=0;i<V;i++){
           visited[i] = stack[i] = false;
        }
        return Cycle_helper(0,visited,stack);

    }
};

int main(){
    Graph g(7);

    g.AddEdge(0,1);
    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(3,4);
    g.AddEdge(4,5);
    g.AddEdge(1,5);
    g.AddEdge(5,6);
    g.AddEdge(4,2); //back edge

    if(g.Contains_Cycle()) cout<<"Yes";
    else cout<<"No";
    return 0;
}
