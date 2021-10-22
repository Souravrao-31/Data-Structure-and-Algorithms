#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    // t = 1;
    while(t--)
    {
        int a, b;
        cin>>a>>b;
        
        b=b+1;
        int count = 0;
        while(b>0)
        {
            b = b/10;
            count++;
        }
        int ans = a*(count-1);
        cout<<ans<<endl;
       
    }
}
