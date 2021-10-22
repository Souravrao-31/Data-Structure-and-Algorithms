//    ĦΔŞŦΔ ŁΔ VƗŞŦΔ ΔŁŴΔ¥Ş ΔŇĐ ₣ØŘ€V€Ř

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>

#define ll long long
#define dd double
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vp vector<pair<ll,ll>>
#define vs vector<string>
#define mll map<ll,ll>
#define mint map<int,int>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define B(a) a.begin()
#define E(a) a.end()
#define For(i,a,b) for(ll i=a;i<b;i++)
#define Forr(i,a,b) for(ll i=a;i>=b;i--)
#define Itr(it,a) for(auto it=a.begin();it!=a.end();it++)
#define F first
#define S second
#define tup3 tuple<ll,ll,ll>
#define tup(ind,a) get<ind>(a)
#define tern(x,y,z) ((x)?y:z)
#define M_P make_pair
#define P_B push_back
#define addt(x,y,z) P_B(make_tuple(x,y,z))
#define add(x,y) P_B(M_P(x,y))
#define till(n) fixed<<setprecision(n)
#define endd "\n"

const int mod = 1e9 + 7;
const ll INFL = LLONG_MAX;
const int INFI = INT_MAX;

using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        vector<int> dp(t.size() + 1, 0), dpTemp(t.size() + 1, 0);
        dp[t.size()] = 1;
        dpTemp[t.size()] = 1;
        
        for(int i = s.size() - 1; i >= 0; i--)
        {
            for(int j = t.size() - 1; j >= 0; j--)
            {
                dpTemp[j] = dp[j];
                
                if(s[i] == t[j])
                {
                    long long temp1 = ((long long)dp[j] + (long long)dp[j + 1]);
                    long long temp2 = 2147483648LL;
                    dpTemp[j] = (int)(temp1 % temp2);
                }
                
            }
            
            dp = dpTemp;
            
        }
        
        return dp[0];
        
    }
};
