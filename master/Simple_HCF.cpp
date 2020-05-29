#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,hcf;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    hcf=arr[0];
    for( int i = 0; i<n;i++)
    {
        hcf= (int)__gcd(hcf,(int)arr[i]);
    }
    cout<<hcf;
    return 0;
}
