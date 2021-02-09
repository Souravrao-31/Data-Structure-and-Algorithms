/**
 * 
 * @description: Floyd Warshall algorithm to find shortest between every pair of vertices
 * 
 * @author: Lakshya Khera
 * 
 * 
 * */


#include<iostream>
#define INF 99999  
#define V 4
using namespace std;

void floydWarshall(int graph[V][V]) {
  int dist[V][V];
  for (int i = 0; i < V; i++)  
    for (int j = 0; j < V; j++)  
      dist[i][j] = graph[i][j];  
  
  for(int k=0;k<V;k++) {
    for(int i=0;i<V;i++) {
      for(int j=0;j<V;j++)
        if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
    }
  }

  for(int i=0;i<V;i++) {
      for(int j=0;j<V;j++)
        cout << dist[i][j]<< " ";
      cout <<endl;
  }

}

int main() {
  int graph[V][V] = { {0, 5, INF, 10},  
    {INF, 0, 3, INF},  
    {INF, INF, 0, 1},  
    {INF, INF, INF, 0}  
  };  

  floydWarshall(graph);  
  return 0;  

  return 0;
}