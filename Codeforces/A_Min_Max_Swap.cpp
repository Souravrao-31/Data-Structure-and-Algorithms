#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        for(int i=0 ; i < n ; i++){
            cin>>a[i];
        }
        for(int j=0 ; j < n ; j++){
            cin>>b[j];
        }
        for (int i = 0; i < n; i++)
        {
            if(a[i] > b[i])
            {
                swap(a[i],b[i]);
            }
        }
        int ans = ((*max_element(a,a+n)) * (*max_element(b,b+n)));
        cout<<ans<<endl;
    }
    return 0;
}