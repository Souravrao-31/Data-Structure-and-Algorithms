#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*
You are provided an array of integers where each element represents the max number of steps you can take to move ahead. You need to check that how many minimum steps required to reach at the end of the array.

Hint - If N==0 you can never move forward, your return INT_MAX (Infinity).

Input Format
First line contains integer t which is number of test case. For each test case, it contains an integers n which the size of array A[]. Next line contains n space separated integers.

Constraints
1<=t<=50
1<=n<=1000
0<=A[i]<=100

Output Format
Print the minimum number of jumps.

Sample Input
1
11
1 3 5 8 9 2 6 7 6 8 9
Sample Output
3
Explanation
1-> 3 (you can pick 5 or 8 or 9 , pick either 8 or 9) -> 8 -> 9
*/
int dp[5000];
int jumps(int i, int n, int a[]){
    if(i==n-1)
    return dp[i]=0;
    if(dp[i]!=-1)
    return dp[i];
    int ans=INT_MAX;
    if(a[i]==0) return INT_MAX-5;/// you have miss this case
    //int jumps=0;
    for(int j=1;j<=a[i]&&(i+j)<n;j++){
        int curans=0;
          //if(i+j<n)
         curans=(1+jumps(i+j,n,a));
        //cout<<curans<<endl;
        ans=min(ans,curans);
    }
    return dp[i]=ans;
}
int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int a[1000];
        for(int i=0;i<n;i++){
            cin>>a[i];
            dp[i]=-1;
        }
        int ans=jumps(0,n,a);
        cout<<ans<<endl;
    }




	return 0;
}