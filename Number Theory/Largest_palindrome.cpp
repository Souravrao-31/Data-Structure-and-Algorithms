#include<bits/stdc++.h>
using namespace std;

#define ll long long


/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers

*/
int reversed(ll number){
   ll rev = 0;
   ll reduced;

   while(number > 0){
       reduced = number %10;
       rev = (rev * 10) + reduced;
       number /= 10;
   }
   return rev;
}

bool isPalindrome(ll number){
   return reversed(number) == number;
}

int largestPalindrome(ll a, ll b){
ll result =  0;
ll largest = 0;

  for(ll x=a;x>=0;x--){
    for(ll y=b;y>=0;y--){
        result = y * x;
        if(isPalindrome(result)){
            largest = max(largest,result);
        }
    }
  }
  return largest;
}

int main(){
    cout<<largestPalindrome(999,999);
    return 0;
}