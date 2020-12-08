#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    long long n ;
    long long mod = 1e9 + 7 ;

    cin >> n ;

    long long power = 1 ;
    for(int i = 1 ; i < n; i++){
        power *= 2 ;
        power %= mod ;
    }

    long long fact = 1 ;

    for(int i = 1 ; i <= n ; i++){
        fact *= i ;
        fact %= mod ;
    }
    long long ans  = (fact - power + mod) % mod ;
    cout << ans << endl;

    return 0 ;
}