#include <iostream>
#include <map>
using namespace std;


/*
Tughlaq introduces a strange monetary system. He introduces copper coins and each coin has a number written on it. A coin n can be exchanged in a bank into three coins: n/2, n/3 and n/4. A coin can also be sold for gold. One can get as much grams of gold as the number written on the coin. You have one copper coin. What is the maximum weight of gold one can get from it?

Input Format
The input file contains a single integer n, the number on the coin.

Constraints
0 <= n <= 1 000 000 000

Output Format
Print the maximum weight of gold you can get.

Sample Input
12
Sample Output
13
*/
#define ll long long
	
	ll coins(ll n,map<ll,ll> &dp){
		//base case
		if(n==1 || n==2 || n==3){
			return n;
		}

		//look up
		if(dp[n]!=0){
			return dp[n];
		}
	ll  ans1=coins(n/2,dp)+coins(n/3,dp)+coins(n/4,dp);
        
		ll ans = max( ans1 , n );
       

		return dp[n] =  ans;
	}

	int main(){
		ll n;
		cin>>n;

		map<ll,ll> dp;
	
		cout<<coins(n,dp)<<endl;

        //for(auto p:dp){
       //     cout<<p.first<<" --> "<<p.second<<endl;
       // }

	}