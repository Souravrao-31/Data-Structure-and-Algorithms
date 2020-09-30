#include<bits/stdc++.h>
using namespace std;

  //Recursive Approach
int Profit(int wines[], int i,int j,int y){
   //Base case
   if(i>j) return 0;

   //Recursive Case
   int op1 = wines[i] * y + Profit(wines,i+1,j,y+1);
   int op2 = wines[j] * y + Profit(wines,i,j-1,y+1);

   return max(op1,op2);

}

int Profit_DP(int wines[], int i,int j,int y,int dp[][100]){
   
   if(i>j) return 0;
   if(dp[i][j]!=0){
       return dp[i][j];
   }

   //Recursive Case
   int op1 = wines[i] * y + Profit_DP(wines,i+1,j,y+1,dp);
   int op2 = wines[j] * y + Profit_DP(wines,i,j-1,y+1,dp);

   return max(op1,op2);

}


int main(){
    
    int wines[] = {2,3,5,1,4};  //o/p = 50
    int n = sizeof(wines)/sizeof(int);
    int y =1;
    int dp[100][100] = {0};
    
    cout<<Profit(wines,0,n-1,y);
    cout<<endl;
    cout<<Profit_DP(wines,0,n-1,y,dp);
    return 0;
}