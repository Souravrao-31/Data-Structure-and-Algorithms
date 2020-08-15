#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff                            first    
#define ss                            second
#define int                           long long
#define pb                            push_back
#define mp                            make_pair
#define pii                           pair<int, int>
#define vi                            vector<int>
#define mii                           map<int, int>
#define pqb                           rity_queue<int>
#define pqs                           rity_queue<int, vi, greater<int>>
#define setbits(x)                    __builtin_popcountll(x)
#define zerobits(x)                   __builtin_ctzll(x)
#define mod                           1000000007
#define inf                           1e18
#define ps(x, y)                      fixed << setprecision(y) << x
#define mk(arr, n, type)              type *arr = new type[n];
#define w(x)                          int x; cin>>x; while(x--)
    
#define pw(b, p)                        pow(b, p) + 0.1
mt19937                                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{

    //write code here
    c_p_c();
    w(t)
    {
        int n;
        cin >> n;
        mk(arr, n, int);

        for (int i = 1; i <= n; ++i)
            cin >> arr[i];

        int cnt[2] = {};

        for(int i = 1; i <= n; ++i)
           cnt[arr[i]%2]++;
           
        if(cnt[0] && cnt[1])   
           cout<<"NO\n";
        else
           cout<<"YES\n";
    }
    return 0;
}

