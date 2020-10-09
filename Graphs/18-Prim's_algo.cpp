#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//Minimum Spanning tree
class Graph{

   //Adjacency List
   vector<pair<int,int> > *l;
   int V;
public:
   Graph(int n){
        V = n;
        l = new vector<pair<int,int> > [n];
   }

   void addEdge(int x,int y,int w){
       l[x].push_back({y,w});
       l[y].push_back({x,w});
   }

   int prim_MST(){
       //most important stuff
       //Init Min heap
       priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > Q;

       //Another array
       //visited array that  denotes whether a node has been included in MST or Not
       bool * visited = new bool[V]{0};
       int ans = 0;

       //begin
       Q.push({0,0});  //weight , node

       while(!Q.empty()){
         //Pick out the edge with min weight
         auto best = Q.top();
         Q.pop();

         int to = best.second;
         int weight = best.first;

         if(visited[to]){
            //discard the edge, and continue
            continue;
         }

         //otherwise take the current edge
         ans += weight;
         visited[to] =1;

         //add the new edges in the queue
        for(auto x:l[to]){
           if(visited[x.first]==0){
               Q.push({x.second,x.first});
           }
        }

       }
       return ans;
   }

};

int main(){
    
    // 4 5
    // 1 2 10
    // 2 3 15
    // 1 3 5
    // 4 2 2
    // 4 3 40
    // 17
    int n,m;
    cin>>n>>m;
    Graph g(n);

    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        g.addEdge(x-1,y-1,w);
    }
    cout<<g.prim_MST();
    return 0;
}