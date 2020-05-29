#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a=0,b=1,c=a;
    cin>>n;
    while (c<=n)
    {
        cout<<c<<'\n';
        a=b;
        b=c;
        c = a + b;
    }
    
    return 0;
}
