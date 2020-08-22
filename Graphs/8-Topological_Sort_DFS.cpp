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
   void AddEdge(T x,T y){
      l[x].push_back(y);
      
   }  
   void dfs_helper(T src, map<T,bool> &visited,list<T> &ordering){
       //Recursive function that will traverse the graph

       visited[src] = true;
       //go to all nbr of that node that is not visited
       for(T nbr : l[src]){
          if(!visited[nbr]){
            dfs_helper(nbr, visited,ordering);
          }
       }


       //at this point
       ordering.push_front(src);
   }

   void DFS(){
       map<T,bool> visited;
       list<T> ordering;
       //Mark all the nodes as not visited in the beginning
       for(auto p:l){
        T node = p.first;
        visited[node] = false;
       }
       //call helper function
       //Iterate over all the vertices and a dfs call
        
      for(auto p:l){
         T node = p.first;
        
         if(!visited[node]){
             dfs_helper(node,visited,ordering);             
         }
      }
      //finally print the list
      for(auto node: ordering){
          cout<<node<<endl;
      }
   }
};

int main(){
     
     Graph<string> g;
    
    g.AddEdge("Python", "DataPreprocessiong");
    g.AddEdge("Python", "Pytorch");
    g.AddEdge("Python", "ML");
    g.AddEdge("DataPreprocessiong", "ML") ;
    g.AddEdge("Pytorch", "DL");
    g.AddEdge("ML", "DL");
    g.AddEdge("DL", "FaceRecognition");
    g.AddEdge("Dataset", "FaceRecognition");
    
    g.DFS();

    return 0;
}