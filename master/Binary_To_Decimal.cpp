#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int bin,dec=0,p=1;
    cin>>bin;
    while (bin > 0)
    {
        dec= dec + (bin%10)*p;
        p*=2;
        bin/=10;
    }
    cout<<dec;
    return 0;
}
