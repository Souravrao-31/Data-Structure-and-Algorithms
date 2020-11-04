#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int dp[100] = {0};
        dp[0] = 1;
        for(int i=1;i<=n;i++){
           dp[i] = 0;
           for(int j=1;j<=2;j++){
                if(i-j>=0) dp[i] += dp[i-j];
           }
        }
    
        return dp[n];
    }
};
/*
70 leetcode
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/
int main(){
    Solution s;
    int n;cin>>n;
    cout<<s.climbStairs(n);
}