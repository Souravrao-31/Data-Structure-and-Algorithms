#include<iostream>
using namespace std;

//recursion 
int knapsack(int wts[],int prices[],int N,int W){
    ///Base Case
    if(N==0||W==0){
        return 0;
    }

    ///Rec Case
    int inc= 0,exc=0;
    if(wts[N-1]<=W){
        inc = prices[N-1] + knapsack(wts,prices,N-1,W- wts[N-1]);
    }

    exc = knapsack(wts,prices,N-1,W);

    return max(inc,exc);
}
//DP solution
long long knapsackDP(int wt[],int price[],int N,int W){

        long long dp[1001][1001] = {0}; // INCREASED THE SIZE 

        for(int n=0;n<=N;n++){
            for(int w=0;w<=W;w++){

                if(n==0||w==0){
                    dp[n][w] = 0;
                }
                else
                {
                    int inc=0,exc = 0;
                    if(wt[n-1]<=w){
                        inc = price[n-1] + dp[n][w-wt[n-1]];
                    }
                        exc = dp[n-1][w];

                    dp[n][w] = max(inc,exc);
                }

            }
        }
        return dp[N][W];
}

int main() {
    int t=1;
    //cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        int wt[n],price[n];
        for(int i=0;i<n;i++) cin>>wt[i];
        for(long long i=0;i<n;i++) cin>>price[i];
        cout<<knapsackDP(wt,price,n,w)<<endl;
       //cout<< maxProfit(n,w,wt,price)<<endl;;
    }
	return 0;
}