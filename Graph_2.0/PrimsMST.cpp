/**
 * 
 * @description: Prim's MST algorithm
 * 
 * @author: Lakshya Khera
 * 
 * */


#include<iostream>
#include<climits>
#define V 5
using namespace std;

int minKey(int key[], bool mstSet[]){ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
    for (int v = 0; v < V; v++) 
        if (mstSet[v] == false && key[v] < min) 
            min = key[v], min_index = v; 
    return min_index; 
} 

void primMST (int Graph[V][V]) {
  int parent[V];
  int key[V];
  bool mstSet[V];

  
  for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
 
  key[0] =0;
  parent[0] = -1;
  for(int count = 0;count < V-1;count++) {
    
    int u = minKey(key, mstSet);
    mstSet[u] = true;
    for(int v =0;v<V;v++) {
      if(Graph[u][v] &&  mstSet[v] == false && Graph[u][v] <key[v]) {
        parent[v] = u;
        key[v] = Graph[u][v];

      }
    }
  }
  cout<<"Edge \tWeight\n"; 
  for (int i = 1; i < V; i++) {
    cout<<parent[i]<<" - "<<i<<" \t"<<Graph[i][parent[i]]<<" \n"; 
  }
}

int main() {
  int Graph[V][V] ={ 
    { 0, 2, 0, 6, 0 }, 
    { 2, 0, 3, 8, 5 }, 
    { 0, 3, 0, 0, 7 }, 
    { 6, 8, 0, 0, 9 }, 
    { 0, 5, 7, 9, 0 } };
  
  primMST(Graph);

  return 0;
}