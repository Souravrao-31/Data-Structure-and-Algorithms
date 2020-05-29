#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll M=1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,sum=0;
    cin>>t;
    pair<ll,ll> S[200000];
    while (t--)
    {
        sum = 0;
        cin>>n;
        for (ll i = 0; i < n; i++)
        {
            cin>>S[i].first;
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> S[i].second;
        }
        sort(S,S+n,[](auto a, auto b){ return a.first < b.first;});
        for (ll i = 0; i < n-1; i++)
        {
            for (ll j = i+1; j < n; j++)
            {
                sum = (sum + (((S[j].first - S[i].first)%M)*max(S[i].second,S[j].second)%M)%M)%M;
            }   
        }
        cout<<sum<<endl;
    }
    

    return 0;
}
