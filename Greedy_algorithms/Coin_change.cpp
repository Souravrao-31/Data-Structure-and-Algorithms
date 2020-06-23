#include<iostream>
#include<algorithm>
using namespace std;
/*
39
20 + 10 + 5 + 2 + 2 +
*/
int make_change(int *coins, int n,int money)
{  int ans=0;
   while(money > 0){
      int idx = upper_bound(coins,coins+n,money) - 1 - coins;//index of coins
      cout<<coins[idx] << " + ";
      money = money - coins[idx];
      ans++;//1 2 ...
      
   }
   return ans;
}
int main(){
    int n;cin>>n;

    int coins[] = {1,2,5,10,20,50,100,200,500,1000,2000};

    int t = sizeof(coins)/sizeof(int);

    make_change(coins, t,n);
    return 0;
}