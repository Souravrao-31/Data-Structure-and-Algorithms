#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int connectTheRopesWith_minCost(int *ropes, int n){
  priority_queue<int, vector<int>, greater<int> > pq(ropes, ropes+ n); //min heap
  int cost=0;
  while(pq.size() > 1){
    int first = pq.top();
    pq.pop();
    int second = pq.top();
    pq.pop();
    cost += (first + second);
    pq.push(first + second);
  }
  return cost;
}
int main(){
    
    int n;
    cin>>n;
    int *arr = new int[n]();//() means initialize it with zero
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]=x;
    }
    cout<<connectTheRopesWith_minCost(arr,n);
    return 0;
}