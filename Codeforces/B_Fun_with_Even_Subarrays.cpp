#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int main(){
ios::sync_with_stdio(0); 
cin.tie(0);
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int a[n],diff = 0,half = (n/2);
    cin>>a[0];
    for (int i = 1; i < n; i++)
    {
        cin>>a[i];
        if(a[i-1] != a[i])
        diff++;
    }
    if(diff == 0)
    cout<<"0"<<endl;
    else if(half < diff)
    cout<<half<<endl;
    else
    cout<<(half - diff)+1<<endl;    
}
    return 0;
}