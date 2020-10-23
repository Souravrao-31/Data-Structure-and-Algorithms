#include <bits/stdc++.h>
using namespace std;

int lcs(char x[],char y[],int m,int n){
    
    if(m==0 || n==0){
        return 0;
    }
    if(x[0]==y[0]){
        return 1+lcs(x+1,y+1,m-1,n-1);
    }
    else{
        return max(lcs(x,y+1,m,n-1),lcs(x+1,y,m-1,n));
    }
}

vector<char> iterative(char x[],char y[],int m,int n){

    int dp[1005][1005]={0};

    for(int i=0;i<=m;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                //cout<<x[i-1]<<" "<<y[j-1]<<endl;
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    /*for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    // }*/
    // int i=m,j=n;
    // string s="";
    // while(i!=0 || j!=0){
    //     if(dp[i-1][j]==dp[i][j-1] && dp[i-1][j]!=dp[i][j]){
    //         i-=1;j-=1;
    //         s= x[i]+s;
    //     }
    //     else if(dp[i-1][j]==dp[i][j-1] && dp[i-1][j]==dp[i][j]){
    //         i-=1;
    //     }
    //     else if(dp[i-1][j]!=dp[i][j-1] ){
    //         if(dp[i][j]==dp[i-1][j]){
    //             i-=1;
    //         }
    //         else if(dp[i][j]==dp[i][j-1]){
    //             j-=1;
    //         }
    //     }
    // }

      vector<char> v;
      int k = dp[m][n];
    //   int t = k;
      for(int i=m;i>=0;)
      {
            for(int j=n;j>=0;)
            {
                  if(dp[i][j]==dp[i][j-1])
                  j--;
                  else if(dp[i][j]==dp[i-1][j])
                  i--;
                  else
                  {
                        v.push_back(y[j-1]);
                        k--;
                        i--;
                        j--;
                        if(k==0)
                        break;
                  }
            }
            if(k==0)
            break;
      }
      return v;

    // return s;
}
int main() {
   char str1[1001],str2[1002];
   cin>>str1>>str2;

   int m=strlen(str1);
   int n=strlen(str2);

   //int ans=lcs(str1,str2,m,n);
//    cout<<iterative(str1,str2,m,n)<<endl;
    vector<char> v=iterative(str1,str2,m,n);
    for(int i=v.size()-1;i>=0;i--)
      cout<<v[i];
   //cout<<ans;
}
