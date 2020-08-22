#include<iostream>
#include<map>
#include<queue>
#include<list>
using namespace std;

//Depth First Traversal (or Search) for a graph is similar to Depth First Traversal of a tree. 
//The only catch here is, unlike trees, graphs may contain cycles, a node may be visited twice. To avoid processing a node more than once, use a boolean visited array.

/*
here we are maintaining a hash map of visited arrays
we start from src if visited we mark as true and we do it with recursion
stack formation through recusrion.
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

   void DFS(T src){
       map<T,bool> visited;
       //Mark all the nodes as not visited in the beginning
       for(auto p:l){
        T node = p.first;
        visited[node] = false;
       }
       //call helper function
       dfs_helper(src,visited);
   }
};

int main(){
     
     Graph<int> g;
     g.AddEdge(0,1);
     g.AddEdge(1,2);
     g.AddEdge(2,3);
     g.AddEdge(3,4);
     g.AddEdge(4,5);

     g.DFS(0);   //Source or initial position 0
     

    return 0;
}