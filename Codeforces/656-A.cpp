#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
int main()
{
	ll t;
	cin>>t;
 
	while(t--){
		ll a[3];
		cin>>a[0]>>a[1]>>a[2];
 
		sort(a,a+3);
		if(a[1]==a[2]) cout<<"YES"<<endl<<a[2]<<" "<<a[0]<<" "<<a[0]<<endl;
		else cout<<"NO"<<endl;
	}
 
	return 0;
}