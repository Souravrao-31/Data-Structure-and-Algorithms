#include <iostream>
using namespace std;
/*
Top down dp approach
recursion + memoization = top down.
*/
int fibon(int n,int dp[]){  //Top down
   //base case
   if(n==0 or n==1){
      return n;
   }
   //recursive
   //Look up
   if(dp[n]!=0){
      return dp[n];       // O(n)
   }
   int ans;
   ans = fibon(n-1,dp) + fibon(n-2,dp);
   return dp[n] = ans;

}
int fibBU(int n){
    int dp[100]={0};
    dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int Space_optFib(int n){

   // Bottom up approach with space optimisation.
    if(n==0 or n==1){
        return n;
    }
    int a=0;
    int b=1;
    int c;

    for(int i=2;i<=n;i++){
        c = a + b;
        a=b;
        b=c;
    }
    return c;
}
int main(){

    int n;
    cin>>n;

    int dp[1000] ={0};
    //cout<<fibon(n,dp)<<endl;

    //cout<<fibBU(n);
    cout<<Space_optFib(n);

    return 0;
}