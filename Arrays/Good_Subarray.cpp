#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int t;cin>>t;
  while(t--){
       
   int n;cin>>n;
   vector<int> a(n);
   string s;cin>>s;

   for(int i=0;i<n;i++){
      a[i] = s[i] - '0' -1;
   }
   map<int, ll> mm;
   ll ans =0;

   mm[0]=1;
   ll r= 0;
   for(int i=0;i<n;i++){
     r += a[i];
     ans += mm[r];
     mm[r]++;
   }
   cout<<ans;

    return 0;
  }
}