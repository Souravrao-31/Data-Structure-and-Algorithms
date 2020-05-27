#include <iostream>
using namespace std;

/*
Through bitmsaking we can find the exponent power
in O(Logn) time complexity

a=2 b=5     2*2*2*2*2
o/p =32
*/
int fun(int a,int n){
  
    int ans=1;

    while(n>0){
     int last_bit =(n&1);
     if(last_bit){
      ans = ans * a;

    }
    a = a*a;
    n = n>>1;

    }
   return ans;
}

int main(){

    int a,n;
    cin>>a>>n;

    cout<<fun(a,n);
    return 0;
}