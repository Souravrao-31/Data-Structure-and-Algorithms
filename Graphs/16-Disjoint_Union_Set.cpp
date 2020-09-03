//Disjoint Union Set (DSU) / Union - find
// also use to find cycle in an undirectional graph
//  -->  Kruskal's algorithm
//  imp data structure
// it deals with disjoints sets

/*
  s1   s2   s3
  1    5    8
  2    6    9
  3    7    
  4      
  5

  sets are disjoints no elements are common  in the sets
  union of set is merging of two sets

  our goal to find and union sets in this Ds in linear time by
  --> Path Compression O(1)
  --> Union By rank    O(1)

  this program have both union by rank and path compression.

*/

#include<iostream>
#include<list>
using namespace std;

//cycle Detection in a undirected graph using DSU

class Graph{
   int V;
   list<pair<int,int>> l;
public:
   Graph(int V){
       this->V = V;
   }   

   int AddEdge(int u,int v){
       l.push_back(make_pair(u,v));
   }

    //Find
    int FindSet(int i,int parent[]){
        //base case
        if(parent[i] == -1){
            return i;
        }
        //Path compression Optimization
        return parent[i] =  FindSet(parent[i], parent);
    }

    //Union
    void Union_set(int x,int y,int parent[],int rank[]){
        int s1= FindSet(x,parent);
        int s2= FindSet(y,parent);

        if(s1!=s2){
            if(rank[s1]<rank[s2]){
               parent[s1]=s2;
               rank[s2] += rank[s1];
            }
            else{
                parent[s2] = s1;
                rank[s1] += rank[s2]; 
            }
        }

    }

   bool contains_Cycle(){
       //DSU logic to check if graph contains cycle or not
       //we created a rank
        int *parent = new int[V];
        int *rank = new int[V];


        for(int i=0;i<V;i++){
            parent[i] = -1;
            rank[i] = 1;
        }

        //iterate over the edge list
        for(auto edge: l){
            int i=edge.first;
            int j=edge.second;

            int s1 = FindSet(i,parent);
            int s2 = FindSet(j,parent);

            if(s1!=s2 ){
            Union_set(s1,s2,parent,rank);
            }
            else{
                cout<<"Same parents "<<s1<<" and "<<s2<<endl;
                return true;
            }

        }
        delete [] parent;
        return false;
   }

};
int main(){
     Graph g(4);

     g.AddEdge(0,1);
     g.AddEdge(1,2);
     g.AddEdge(2,3);
     //g.AddEdge(3,0);  //disconnecting last edge

     cout<<g.contains_Cycle();
    return 0;
}