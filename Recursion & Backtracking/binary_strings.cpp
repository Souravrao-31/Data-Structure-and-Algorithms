/*
 #Count binary strings of length of N, which have no consecutive ones?
 N=2
 ans = 00,01,10  = 3
 f(n) = f(n-1) + f(n-2)
*/
#include<iostream>
using namespace std;
int f(int n){
   if(n==0){
     return 0;
   }
   if(n==1){
     return 2;
   }
   return f(n-1) + f(n-2);    //function is incomplete
}
int main(){
      int n;
      cin>>n;
      cout<<f(n);
    return 0;
}