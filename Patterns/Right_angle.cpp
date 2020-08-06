#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,j;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
            cout<<" \t";
        for(j=i;j<i+i;j++)
            cout<<j<<"\t";
        for(int k=j-2;k>=i;k--)
            cout<<k<<"\t";
        cout<<endl;
    }
}
