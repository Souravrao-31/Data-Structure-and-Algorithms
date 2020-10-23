#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX_CHAR 256
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int n=s.length();
		ll dp[n+1];
		dp[0]=1;
		vector<int> mp(MAX_CHAR,-1);
		for(int i=1;i<=n;i++)
		{
			
			if(mp[s[i-1]]!=-1)
			{
				dp[i]=((2*dp[i-1])-dp[mp[s[i-1]]]+MOD)%MOD;
			}
			else
			dp[i]=(2*dp[i-1])%MOD;
			mp[s[i-1]]=i-1;

		}
		cout<<dp[n]%MOD<<endl;
	}
	return 0;
}