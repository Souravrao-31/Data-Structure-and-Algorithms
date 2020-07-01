


#include<bits/stdc++.h>
using namespace std;
void solve()
{
	
	
// separate on the basis of odd and even numbers
// then take x pair of odd numbers ( o+o =e )
// 	then take y pair of even numbers ( e+e = e)
//	x+y==n-1
// gcd >=2
int n,x; cin>>n;
vector <int> od,ev;
for(int i=0;i<2*n;i++)
{
cin>>x;
if(x%2==0)
ev.push_back(i+1); // indices
else
od.push_back(i+1); // indices
}
int ct=0; // To limit b = n-1
for(int i=0;i<od.size();i++)
{
if(i+1<od.size() && ct<n-1)
{
ct++;
cout<<od[i]<<' '<<od[i+1]<<"\n";
}
i++;
}
for(int i=0;i<ev.size();i++)
{
if(i+1<ev.size() && ct<n-1)
{
ct++;
cout<<ev[i]<<' '<<ev[i+1]<<"\n";
}
i++;
}
return;
}
int main()
{
ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	cin>>t;
while(t--)
{
solve();
}
return 0;
}
