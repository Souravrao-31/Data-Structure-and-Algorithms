#include <iostream>
using namespace std;

/*
Given three numbers a,b,c. Calculate (a^b)mod c.

Input Format
Single line containing three integers a,b,c separated by space.

Constraints
1<=a,b,c<=100000

Output Format
Print (a^b)mod c.

Sample Input
2 2 3
Sample Output
1
Explanation
(2^2)mod 3=4 mod 3 = 1
*/
long long modular(long long base, long long exp, int mod) {
   long long res = 1;
   while (exp > 0) {
      if (exp % 2 == 1)
         res= (res * base) % mod;
      exp = exp >> 1;
      base = (base * base) % mod;
   }
   return res;
}
int main() {
   long long b, e;
   int mod;
   cout<<"Enter Base : ";
   cin>>b;
   cout<<"Enter Exponent: ";
   cin>>e;
   cout<<"Enter Modular Value: ";
   cin>>mod;
   cout<<modular(b, e , mod);
   return 0;
}