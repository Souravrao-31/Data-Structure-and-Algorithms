#include<iostream>
using namespace std;

/*
We are given two coins of value x and y. We have to find the maximum of value of a XOR b where x <= a <= b <= y.

Input Format
We are given two integers x and y

Constraints
l <= r <= 1000

Output Format
Print the maximum value of a XOR b

Sample Input
5
6
Sample Output
3
 */
int main () {
	int m,n;    cin>>m>>n;
    int ans=0;
    if(m>n) swap(m,n);
    for(int i=m;i<n;i++){
        for(int j=i+1;j<=n;j++)
            ans=max(ans,i^j);
    }
    cout<<ans;
	
	
	return 0;
}
