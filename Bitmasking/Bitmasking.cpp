#include <iostream>
using namespace std;

bool isodd(int n){
     return(n & 1);
}
/*
getbit()
it will give the value of bit
5=000101
here 0 and 2 position is 1
and 
*/
int getbit(int n,int i){
     int mask =(1<<i);
     int bit  =(n & mask)>0 ? 1:0;   //always use round brackets.
     return bit;
}
int setbit(int n,int i){
     int mask =(1<<i);
     int ans =n|mask;
     return ans;
}
void clearbit(int &n,int i){
     int mask = ~(1<<i);
      n = n & mask;
}
void updatebit(int &n,int i,int v){
  int mask =~(1<<i);
  int cleared_n =n & mask;
  n = cleared_n | (v<<i);
}
int clearIbits(int n,int i){
     int mask = (-1<<i);
     return n &mask;
}
int clearRangeItoJ(int n,int i,int j){
     int ones = (~0);
     int a = ones <<(j+1);
     int b =(1<<i)-1;
     int mask =a|b;
     int ans =n & mask;
     return ans;
}
int main(){
    int n=15;
    int i;
    //cin>>i;
    //cout<<isodd(n);

    // cout<<getbit(n,i)<<endl;

     //n=setbit(n,i);
     //cout<<"ANS "<<n<<endl;

    // clearbit(n,i);
     //cout<<n<<endl;

     //update the bit
     //updatebit(n,2,0);
     //updatebit(n,3,1);
    // cout<<n<<endl;

    //cout<<clearIbits(n,i)<<endl;

    cout<<clearRangeItoJ(n,1,2);
   
   
    return 0;
}