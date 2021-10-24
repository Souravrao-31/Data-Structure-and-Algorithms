// Codeforces problem link: https://codeforces.com/contest/431/problem/C

#include<bits/stdc++.h>
#define ll long long int
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
#define MOD 1000000007
#define MAX 105

ll n, k, d, dp[MAX][MAX];
ll solve(ll total_weight, ll max_weight){
    if(total_weight>n) return 0;
    if(total_weight==n){
        if(max_weight>=d) return 1;
        else return 0;
    }
    ll &ret = dp[total_weight][max_weight];
    if(ret!=-1) return ret;
    ret=0;
    for(ll i=1; i<=k; i++){
        ret += solve(total_weight+i, max(max_weight, i));
        ret %= MOD;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k>>d;
    mem(dp,-1);
    cout<<solve(0,0)<<endl;
    return 0;
}
