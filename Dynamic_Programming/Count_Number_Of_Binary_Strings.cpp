
#include <iostream> 
using namespace std; 
#define ll long long int

/*
You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

Input Format
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.

Constraints
1<=t<=100 1<=n<=90

Output Format
Print the number of all possible binary strings.

Sample Input
2
2
3
Sample Output
3
5
Explanation
1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101
*/

ll countStrings(ll n) 
{ 
  ll a[n], b[n]; 
  a[0] = b[0] = 1; 
  for (ll i = 1; i < n; i++) 
  { 
    a[i] = a[i-1] + b[i-1]; 
    b[i] = a[i-1]; 
  } 
  return a[n-1] + b[n-1]; 
} 
int main() 
{
  ll t;
  cin>>t;
  while(t--)
  {
  ll n;
  cin>>n;
  ll ans =  countStrings(n);
  cout<<ans<<endl;
  }
  return 0; 
}
