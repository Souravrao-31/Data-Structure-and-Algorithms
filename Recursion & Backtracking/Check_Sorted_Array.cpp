#include <iostream>
using namespace std;
bool sorted(long long int a[],int n)
{
    if(n==0 or n==1)
    {
        return true;
    }
    if(a[0]<=a[1] and sorted(a+1,n-1))
    {
        return true;
    }
    return false;
   
}
int main() {
    int n;
    cin>>n;
     long long int a[100000];
    for(long long int i=0; i<n; i++)
    {
        cin>>a[i];
    }
     if(sorted(a,n)==1)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    };
}
