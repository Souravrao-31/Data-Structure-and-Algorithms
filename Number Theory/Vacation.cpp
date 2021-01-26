#include<bits/stdc++.h>
using namespace std;

int Solve(int A, vector<int> &B){
    int n=A;
    int m=B.size();
    int  dp[100][100];
    vector<int> v(m,0);
    for(int i=0;i<m;i++) 
    v[i]=B[i];

    memset(dp,0,sizeof(dp));
    for(int i=0;i<m;i++){
        dp[0][i] =1;
       // v[i]--;
    }

    int sum=m;

    for(int i=1;i<n;i++){
        int x=0;
        for(int j=0;j<m;j++){
            if(v[j]>0){
                dp[i][j]=sum;
                v[j]--;
            }
            else{
                dp[i][j]=sum-dp[i-1][j];
                v[j]=B[j];
            }
            x += dp[i][j];
        }
        sum=x;
    }
    

    int res =0;
    for(int i=0;i<m;i++){
        res +=dp[n-1][i];
    }
    return res;

}


int main(){
    int N;cin >> N;
    int A;cin >> A;

    vector<int> v;

    for (int i = 0; i < A; i++)
    {
        int x;cin >> x;
        v.push_back(x);
    }

    cout<<Solve(A,v);
    
   
    return 0;
}