/*
#friends pairing problem
 
Given N, friends who want to go to a party on bikes.each guy can go single, or as acouple.
Find the numbers of ways in which N friends can go to the party.

N=3
ways=4

*/
#include<iostream>
using namespace std;

int factorial(int n)
{
    // single line to find factorial
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
int f(int n){
   if(n==0){
     return 1;
   }
   if (n == 1)
   {
       return 1;
   }
   if (n == 2)
   {
       return 2;
   }
   return f(n-1) + f(n-2);   //function is incomplete
}
int main(){
   int n;
   cin>>n;

    return 0;
}