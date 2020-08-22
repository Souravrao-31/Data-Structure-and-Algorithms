#include<iostream>
#include<map>
#include<queue>
#include<list>
using namespace std;

/*

*/
template<typename T>
class Graph{
  map<T, list<T>> l;
public:
   void AddEdge(int x,int y){
      l[x].push_back(y);
      l[y].push_back(x);
   }  
   void dfs_helper(T src, map<T,bool> &visited){
       //Recursive function that will traverse the graph

       cout<<src<<" ";
       visited[src] = true;
       //go to all nbr of that node that is not visited
       for(T nbr : l[src]){
          if(!visited[nbr]){
            dfs_helper(nbr, visited);
          }
       }
   }

   void DFS(){
       map<T,bool> visited;
       //Mark all the nodes as not visited in the beginning
       for(auto p:l){
        T node = p.first;
        visited[node] = false;
       }
       //call helper function
       //Iterate over all the vertices and a dfs call
        int cnt = 0;
      for(auto p:l){
         T node = p.first;
        
         if(!visited[node]){
            cout<<"Component "<<cnt<<" -->";
             dfs_helper(node,visited);
             cnt++;
             cout<<endl;
         }
      }
   }
};

int main(){
     
     Graph<int> g;
     g.AddEdge(0,1);
     g.AddEdge(1,2);
     g.AddEdge(2,3);
     g.AddEdge(0,4);
     g.AddEdge(0,3);
 
     g.AddEdge(5,6);
     g.AddEdge(6,7);

     g.AddEdge(8,8);
     g.DFS();   //Source or initial position 0
     

    return 0;
}