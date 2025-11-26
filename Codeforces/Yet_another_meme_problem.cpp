/*Problem Statement - You are given two integers A and B, calculate the number of pairs (a,b) such that 1≤a≤A, 1≤b≤B, 
and the equation a⋅b+a+b=conc(a,b) is true; conc(a,b) is the concatenation of a and b (for example, conc(12,23)=1223, 
conc(100,11)=10011). a and b should not contain leading zeroes.*/

//Problem Link - https://codeforces.com/contest/1288/problem/B

#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    // t = 1;
    while(t--)
    {
        int a, b;
        cin>>a>>b;
        
        b=b+1;
        int count = 0;
        while(b>0)
        {
            b = b/10;
            count++;
        }
        int ans = a*(count-1);
        cout<<ans<<endl;
       
    }
}
