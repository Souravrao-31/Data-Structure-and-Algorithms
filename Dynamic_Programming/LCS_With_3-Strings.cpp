#include <bits/stdc++.h>
using namespace std;
int lcs(string a,string b,string c){
    int l1=a.length();
    int l2=b.length();
    int l3=c.length();
    int dp[l1+1][l2+1][l3+1]={}
    for(int i=0;i<=l1;i++) dp[i][0][0]=0;
    for(int i=0;i<=l2;i++) dp[0][i][0]=0;
    for(int i=0;i<=l3;i++) dp[0][0][i]=0;
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            for(int k=1;k<=l3;k++){
                if(a[i-1]==b[j-1] && c[k-1]==b[j-1]) dp[i][j][k]=1+dp[i-1][j-1][k-1];
                else {
                    int max1=max(dp[i-1][j][k],dp[i][j-1][k]);
                    int max2=max(dp[i][j][k-1],dp[i-1][j-1][k]);
                    int max3=max(dp[i-1][j][k-1],dp[i][j-1][k-1]);
                    dp[i][j][k]=max(max1,max(max2,max3));
                    // dp[i][j][k]=max(max1,max(max2,max3));
                }
            }
        }
    }
    return dp[l1][l2][l3];
   
}
int main() {
    string a,b,c;
    cin>>a>>b>>c;
    cout<<lcs(a,b,c);
    return 0;
}
