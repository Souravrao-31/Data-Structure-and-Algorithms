#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

void findIndices(ll int arr[], ll int s, ll int n, ll int key)
{
    if(s==n)
        return;
    if(arr[s]==key){
        cout<<s<<" ";
        findIndices(arr, s+1, n, key);
    }
    else
        findIndices(arr, s+1,n,key);
}

int main()
{
    ll int n; cin>>n; ll int arr[n];
    for(ll int i=0;i<n;i++)
        cin>>arr[i];
    ll int key; cin>>key;
    ll int s=0;
    findIndices(arr, s, n, key);
    return 0;
}
