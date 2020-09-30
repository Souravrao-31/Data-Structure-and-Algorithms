#include<iostream>
#include<climits>

using namespace std;

/*

length -1 2 3 4 5 6 7 8
Price - 1 5 8 9 10 17 20
Max Profit = 22

length - 1 2 3 4  5  6  7  8
Price - 3 5 8 9 10 17 17 20
Max Profit = 24

*/
class Solution{

public:
  int Max_Profit_Rec(int prices[], int n){
    //Base case
    if(n<=0){
     return 0;
    }

    //rec case
    int ans = INT_MIN;

    for(int i=0;i<n;i++){
       int cut = i+1;
       int current_ans = prices[i]  + Max_Profit_Rec(prices,n-cut);
       ans = max(ans,current_ans);
    }
    return ans;
  }
  int Max_Profit_BU(int *prices, int n){

      int dp[100] ={0};
      dp[0]  =0;

      for(int len=1;len<=n;len++){
        int ans = INT_MIN;
         for(int j=0;j<len;j++){
            int cut = j+1;
            int current_ans = prices[j] + dp[len - cut];
             ans = max(ans,current_ans);
         }
         dp[len] = ans;
      }
      return dp[n];
  }
};
int main(){

    int prices[] = {1,5,8,10,17,17,20};
    int n = sizeof(prices)/sizeof(int);

    Solution s;
    cout<<s.Max_Profit_Rec(prices,n)<<endl;
    cout<<s.Max_Profit_BU(prices,n);
    return 0;
}