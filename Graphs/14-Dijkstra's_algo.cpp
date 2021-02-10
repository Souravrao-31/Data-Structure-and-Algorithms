#include<bits/stdc++.h>
using namespace std;


/*
Given a graph and a source vertex in the graph, find shortest paths from source to all vertices in the given graph.
Dijkstra’s algorithm is very similar to Prim’s algorithm for minimum spanning tree.
 Like Prim’s MST, we generate a SPT (shortest path tree) with given source as root.
  We maintain two sets, one set contains vertices included in shortest path tree, 
other set includes vertices not yet included in shortest path tree. At every step of the algorithm,
 we find a vertex which is in the other set (set of not yet included) and has a minimum distance from the source.

Below are the detailed steps used in Dijkstra’s algorithm to find the shortest path from a single source vertex to all other vertices in the given graph.
Algorithm
1) Create a set sptSet (shortest path tree set) that keeps track of vertices included in shortest path tree, i.e., 
    whose minimum distance from source is calculated and finalized. Initially, this set is empty.
2) Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE. 
   Assign distance value as 0 for the source vertex so that it is picked first.
3) While sptSet doesn’t include all vertices
….a) Pick a vertex u which is not there in sptSet and has minimum distance value.
….b) Include u to sptSet.
….c) Update distance value of all adjacent vertices of u. To update the distance values, iterate through all adjacent vertices.
     For every adjacent vertex v, if sum of distance value of u (from source) and weight of edge u-v, is less than the distance value of v, then update the distance value of v.
*/


template<typename T>

class Graph{
    unordered_map<T, list<pair<T,int>> > m; //we can use map to sort 
public:
   
   void AddEdge(T u, T v, int dist,bool bidir=true){
       m[u].push_back(make_pair(v,dist));

       if(bidir){
         m[v].push_back(make_pair(u,dist));
       }
   }
   void printAD(){
        // Let try t print the adj list
        //Iterate over all the key value pairs in the map
        for(auto j:m ){

             cout<<j.first<<"->";

             //iteare over all the list of the cities
            for(auto l: j.second){
                cout<<"("<<l.first<<","<<l.second<<")";
            } 
    
             cout<<endl;
        }

   }
   void dijkstraSSSP(T src){
        unordered_map<T,int> dist;

        //Set all distance to infinity
        for(auto j:m){
              dist[j.first] = INT_MAX;
        }

        //make a set to find a out node with the minimum distance
        set<pair<int, T>> s;

        dist[src] = 0;

        s.insert(make_pair(0,src));

        while(!s.empty()){
              //find the pair at the front
            auto p =  *(s.begin());
            T node = p.second;

            int nodeDist = p.first;
            s.erase(s.begin());

            //iterate over neighbour / children of the current node
            for(auto childpair: m[node]){
               
               if(nodeDist + childpair.second < dist[childpair.first]){
                   //In the set updation of a particular is not possible
                   // we have to remove the old pair, and insert th new pair to simulation updation

                   T dest = childpair.first;
                   auto f = s.find( make_pair(dist[dest], dest) );
                   if( f != s.end()){
                       s.erase(f);
                   }

                   //Insert the new pair
                   dist[dest] = nodeDist + childpair.second;
                   s.insert(make_pair( dist[dest],  dest));
               }

            }

        }

        for(auto d: dist){

            cout<<d.first<<" is located at distance of "<<d.second<<endl;
        }


   }

};

int main(){

//     Graph<int> g;

//     g.AddEdge(1,2,1);
//     g.AddEdge(1,3,4);
//     g.AddEdge(2,3,1);
//     g.AddEdge(3,4,2);
//     g.AddEdge(1,4,7);
//    g.printAD();

//    g.dijkstraSSSP(1);


    Graph<string> india;
    india.AddEdge("Amritsar","Delhi",1);
    india.AddEdge("Amritsar","Jaipur",4);
    india.AddEdge("Jaipur","Delhi",2);
    india.AddEdge("Jaipur","Mumbai",8);
    india.AddEdge("Bhopal","Agra",2);
    india.AddEdge("Mumbai","Bhopal",3);
    india.AddEdge("Agra","Delhi",1);
    //india.printAD();

   india.dijkstraSSSP("Amritsar");

    return 0;
}