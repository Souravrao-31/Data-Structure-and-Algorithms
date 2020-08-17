#include <iostream>
using namespace std;
#define ll long long int
/*
we are going to convert the decimal to bianry
n=13
o/p=1101
*/
int fun(ll n){

    ll ans=0;
    ll p=1;

    while(n>0){
        ll last_bit = (n & 1);
        
        ans += p *last_bit;
        p = p*10;
        n = n>>1;
        
    }
    return ans;

}

int main(){
   ll n;
    cin>>n;
    cout<<fun(n)<<endl;

    return 0;
}