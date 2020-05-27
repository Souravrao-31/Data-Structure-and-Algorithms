#include<iostream>
#include<deque>
#include<climits>
using namespace std;

/*
  contigous sub array sum
  let n=7
  3 -2 -2 4 3 -1 5
  k=8 which is equals to maximum
  o/p = 4 which is shortest length subarray to orm

  we are going to use deque to store prefix value,and its address.
*/
int SubarraySum(int *arr,int n,int k){

    int *sum = new int[n+1];
    int x=0;
    for(int i=0;i<n;i++){
        x +=arr[i];
        sum[i]=x;
    }

    deque<pair<int ,int > > q;
    q.push_back({0,-1});

    int ans =INT_MAX;
  
    for(int i=0;i<n;i++){
        while(!q.empty() && sum[i]-q.front().first >= k){
            //we need to calculate the ans
            ans =min(ans,i-q.front().second);
            q.pop_front();  
        }
        while(!q.empty() && sum[i] <= q.back().first){
            q.pop_back();
        }
        q.push_back({sum[i],i});
    }
    if(ans == INT_MAX){
         return -1;
    }
    else{
        return ans;
    }


}
int main(){
    int n;
    cin>>n;
    int *arr = new int [n+1];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    cout<<SubarraySum(arr,n,k)<<endl;
   
    return 0;
}