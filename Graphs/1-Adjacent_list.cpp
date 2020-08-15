#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    //Array of list
    list<int> *l;   //
    public:
    Graph(int V){
        this->V=V;
        l = new list<int>[V]; //
    }
    void AddEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void PrintAdjList(){
     
     //iterate all over vertices
     for(int i=0;i<V;i++){
        cout<<"Vertex "<<i<<"-> ";
        for(int neighbour:l[i]){
        cout<<neighbour<<",";
        }
        cout<<endl;
     }

    }
};

int main(){
    Graph g(4);
    g.AddEdge(0,1);
    g.AddEdge(0,2);
    g.AddEdge(1,3);
    g.AddEdge(2,3);

    g.PrintAdjList();
    return 0;
}