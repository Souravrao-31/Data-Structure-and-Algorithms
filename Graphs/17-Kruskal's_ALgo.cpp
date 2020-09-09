#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//DSU Data Structure
//Path Compression + Union By Rank

//Algorithm for minimum Spnning tree
/*
   a undirected graph has V vertex to form MSt
   V-1 edge requires
   
*/
class DSU{

    int *parent;
    int *rank;
public:
   DSU(int n){
    parent = new int[n];
    rank = new int[n];

    //parent -1, rank = 1
    for(int i=0;i<n;i++){
        parent[i] = -1;
        rank[i] = 1;
    }
   } 

   //Find Fuction
   int find(int i){
     //base case
    if(parent[i] == -1){
    return i;
    }
    //otherwise
    return parent[i] =find(parent[i]);
   }

   //Unite (union)
   void unite(int x,int y){
        int s1= find(x);
        int s2 = find(y);

        if(s1 != s2){
        //Union by rank
        if(rank[s1] < rank[s2]){
            parent[s1]= s2;
            rank[s2] += rank[s1]; 
        }
        else{
            parent[s2] = s1;
            rank[s1] += rank[s2]; 
           } 
        }
    }
};


class Graph{

    vector<vector<int>> edgelist;
    int V;
public:
  Graph(int V){
    this->V = V;
  }    

  void addEdge(int x,int y,int w){
       edgelist.push_back({w,x,y});
  }
  int Kruskal_MST(){
    //main logic = easy
    //sort all the edges based upon weight
    sort(edgelist.begin(),edgelist.end());
   
    //Init DSU
    DSU s(V);

    int ans = 0;
    for(auto edge: edgelist){
       int w = edge[0];
       int x = edge[1];
       int y = edge[2];

       //take that edge in MST if it doesn't form a cycle
       if(s.find(x) != s.find(y)){
          s.unite(x,y);
          ans += w;
       }
    }
    return ans;
  }
};
int main(){

    // Graph g(4);
    // g.addEdge(0,1,1);
    // g.addEdge(1,3,3);
    // g.addEdge(3,2,4);
    // g.addEdge(2,0,2);
    // g.addEdge(0,3,2);
    // g.addEdge(1,2,2);

    // cout<<g.Kruskal_MST()<<endl;


    //Input 
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

    cout<<g.Kruskal_MST()<<endl;
    return 0;
}