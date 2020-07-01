#include <bits/stdc++.h>
using namespace std;
/*

Greedy approah can  also sovle this qns but
using DP we can solve It on diff coins system.
*/
int MinCoins(int coins[], int n, int dp[], int t)
{
    // Top down Approach
    //base case
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    //Rec case
    int ans = INT_MAX;
    for (int i = 0; i < t; i++)
    {
        if (n - coins[i] >= 0)
        {
            int sub = MinCoins(coins, n - coins[i], dp, t);
            ans++;
            ans = min(ans, sub + 1);
        }
    }
    
    dp[n] = ans;
    return dp[n];
}

int MinCoinsBU(int n ,int coins[],int t){
    int dp[500] ={0};
    
    //iterate through all states 1....n
    for(int j= 1; j <= n; j++){

        //Init the current ans as infinity
        dp[j] = INT_MAX;
        for (int i = 0; i < t; i++)
        {
            if (n - coins[i] >= 0)
            {
                int sub = dp[n-coins[i]];
                dp[j] = min(dp[j], sub + 1);
            }
        }
    }
    return dp[n];
}
int main()
{

    int n;
    cin >> n;
    int coins[] = {1, 2, 5};
    int t = sizeof(coins) / sizeof(int);
    int dp[500] = {0};
    
    
    cout << MinCoins(coins, n, dp, t);

    //cout << MinCoinsBU(n,coins, t);   //error in this function
}

