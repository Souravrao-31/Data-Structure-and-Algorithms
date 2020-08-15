#include<iostream>
#include<list>
#include<unordered_map>
#include<cstring>
using namespace std;

class Graph{
   unordered_map<string, list<pair<string,int> > > l;
public:
   void AddEdge(string x, string y,bool bidir, int wt){
       l[x].push_back(make_pair(y,wt));
        if(bidir)
           l[y].push_back(make_pair(x,wt));
   }
   void PrintAdjlist(){
       //Iterate over all the keys in the map
       for(auto p:l){
          string city = p.first;
          list<pair<string,int> > nbrs = p.second;

          cout<<city<<"->";
          for(auto nbr: nbrs){
              string dest = nbr.first;
              int dist = nbr.second;

              cout<<dest<<" "<<dist<<",";
          }
          cout<<endl;
       }
   }
};

int main(){

    Graph g;
    g.AddEdge("A","B",true,20);
    g.AddEdge("A","C",true,10);
    g.AddEdge("C","D",true,40);
    g.AddEdge("D","B",true,30);    
    g.AddEdge("A","D",false,50);    
    
    g.PrintAdjlist();
    return 0;
}