#include <iostream>
using namespace std;

//recusrsion sol has bad complexity near exponential
// use DP to solve 
int ways(int n,int m){
    //base case
   if(n<m){
        return 1;
    }
    if(n==m){
        return 2;
    }
    int ans = 0;
   ans=ways(n-1,m)+ways(n-m,m-1);
    return ans;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<ways(n,m)<<endl;
    }
    return 0;
}
