#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t,n,term;
    cin>>t;
    while (t--)
    {
        cin>>n;
        if (n%2==0)
        {
            cout<<(n/2)<<'\n';
        }
        else
        {
            cout<<-(n+1)/2<<'\n';
        }
    }
    
    return 0;
}
