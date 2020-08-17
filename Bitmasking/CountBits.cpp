#include <iostream>
using namespace std;
/*
coutn then bits in binary
N=13 binary=00001101  o/p =3
total 3 ones in the binary
*/
//O(n)
int countBits(int n){
    int ans=0;

    while(n>0){
    ans +=(n&1);
    n= n>>1;
    }
    return ans;

}
//T(n) =O(Log n)
int countBits_fast(int n){    
    int ans = 0;

    while (n > 0)
    {
    n =n & (n-1);
    ans++;
    }
    return ans;
}    

int main(){
    int n;
    cin>>n;
    cout<<countBits(n)<<endl;
    cout << countBits_fast(n)<<endl;
    return 0;
}