#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int oct,dec=0,bin=0,p=1;
    cin>>oct;
    while (oct > 0)
    {
        dec = dec + (oct %10) * p;
        oct /= 10;
        p *= 8;
    }
    p=1;
    while (dec > 0)
    {
        bin = bin + (dec % 2) * p;
        p *= 10;
        dec /= 2;
    }
    cout<<bin;
    return 0;
}
