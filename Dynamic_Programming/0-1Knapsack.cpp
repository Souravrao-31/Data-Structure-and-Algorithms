#include<iostream>
using namespace std;
#define ll long long int
int dp[1001][1001];


ll maxValue(int s,int  * size,int * profit,int i)
{
	//Base case
	if(i==0 || s==0)
	return  0;

	if(dp[i][s]!=-1)
	{
		return dp[i][s];
	}
	//Rec case
	
	if(size[i-1]<=s)
	return dp[i][s]=max((profit[i-1]+maxValue(s-size[i-1],size,profit,i-1)),maxValue(s,size,profit,i-1));
	else
	return dp[i][s]=maxValue(s,size,profit,i-1);
}
int main() {
	int s,n;
	cin>>n>>s;
	int size[n],profit[n];
	for(int i=0;i<n;i++)
	{
		cin>>size[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>profit[i];
	}
	memset(dp,-1,sizeof dp);
	cout<<maxValue(s,size,profit,n)<<endl;
	
	return 0;
}