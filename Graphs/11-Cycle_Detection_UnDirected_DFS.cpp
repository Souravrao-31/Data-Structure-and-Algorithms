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

    bool Cycle_helper(int node, bool *visited, int parent){
         
        visited[node] = true;
        

        for(auto nbr: l[node]){
            //two cases
            if( !visited[nbr] ) {
                // Go and recursively visit the nbr
               bool cycle_mila = Cycle_helper(nbr,visited,node);
               if(cycle_mila){
                   return true;
               }
            }

            //nbr is visited but nbr should not be equal to parent
            else if(nbr != parent){
               return true;
            }
        }
            return false;
    }

       
    

    bool Contains_Cycle(){
        //Check for cycle in directed graph
        bool *visited = new bool[V];
    
       
        for(int i=0;i<V;i++){
           visited[i] =false;
        }
       return Cycle_helper(0,visited, -1);

    }
};

int main(){
    Graph g(5);

    g.AddEdge(0,1);
    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(3,4);
   // g.AddEdge(4,0);


    if(g.Contains_Cycle()) cout<<"Yes";
    else cout<<"No";
    return 0;
}
