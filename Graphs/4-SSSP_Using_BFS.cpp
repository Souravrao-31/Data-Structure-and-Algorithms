#include<iostream>
#include<map>
#include<queue>
#include<list>
#include<climits>
using namespace std;

//It is visiting every Vertices in a graph
//BFS is traversal or way of visiting
// two ways -> BFS and DFS.
// as from the name Breadth it means wi start with the source and visit neighbour.
template<typename T>
class Graph{
  map<T, list<T>> l;
public:
   void AddEdge(int x,int y){
      l[x].push_back(y);
      l[y].push_back(x);
   }  
   //Single shortest source path by using BFS
   void BFS(T src){
       map<T,int> dist;
       queue<T> q;
       
       //All other nodes will have int_max
       for(auto node_pair:l){
            T node = node_pair.first;
            dist[node] = INT_MAX;
       }
       q.push(src);
       dist[src] = 0;

       while(!q.empty()){

           T node = q.front();
           q.pop();
          // cout<<node<<" ";

           for(int nbr: l[node]){
              if(dist[nbr]==INT_MAX){
                  q.push(nbr);
                  //Mark that nbr as visited
                  dist[nbr] = dist[node] + 1;
              }
           }
       }

       //Print the distance from every node
       for(auto node_pair: l){
           T node = node_pair.first;
           int d  = dist[node];
           cout<<"Node "<<node<<" Dist from src "<<d<<endl;
       }
   }
};

int main(){
     
     Graph<int> g;
     g.AddEdge(0,1);
     g.AddEdge(1,2);
     g.AddEdge(2,3);
     g.AddEdge(3,4);
     g.AddEdge(4,5);

     g.BFS(0);   //Source or initial position 0


    return 0;
}