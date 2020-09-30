#include <iostream> 
#include <vector>


//4 3
//7

/*
 6 3
24
24
1 1 2 4 7 13 24 24
*/
using namespace std; 

class Solution{

public:
      //O(NK)  O(N)
    int Ladder_TD(int n,int k){
         //Base case
          if(n==0) return 1;

        //lookup 
       int dp[100] = {0};
        if(dp[n] != 0){
           return dp[n];
        }

        //rec Case
        int ways = 0;
        for(int i=1;i<=k;i++){
          if(n-i >= 0){
              ways += Ladder_TD(n-i,k);
          }
        }
        return dp[n] =  ways;
    }
   
      //O(N*K) 
    int Ladder_BU(int n,int k){
        int dp[100] = {0};
        dp[0] = 1;
        for(int i=1;i<=n;i++){
           dp[i] = 0;
           for(int j=1;j<=k;j++){
                if(i-j>=0) dp[i] += dp[i-j];
           }
        }
        
        //Bottom up Dp table
        // for(int i = 0;i<=n;i++){
        //    cout<<dp[i]<<" ";
        // }

        return dp[n];
    }


    //Optimised Problem
    int ladder(int n,int k){
        int dp[100] = {0};
        dp[0] = dp[1] = 1;

        for(int i=2;i<=k;i++){
            dp[i] = 2*dp[i-1];
        }
         for(int i=k+1;i<=n;i++){
            dp[i] = 2*dp[i-1] - dp[i-k-1];
        }
        //print Dp table
        //  for(int i = 0;i<=n;i++){
        //    cout<<dp[i]<<" ";
        // }
        return dp[n];
    }


};


int main() 
{  
     int N,K;
     cin>>N>>K;
     Solution s;
    cout<<s.Ladder_TD(N,K)<<endl;
    cout<<s.Ladder_BU(N,K)<<endl;
    cout<<s.ladder(N,K);
	return 0; 
} 