#include<iostream>
using namespace std;

#define ll long long
/*
   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 ......n.
   we will make array where we will store our numbers,
   then we will mark the number which are divisible of numbers that means
   that number are not prime.
*/

 void seive(int *p){  //O(n loglogn)
      
      //first mark all odd numbers
      for (ll i = 3; i < 1000000; i += 2)
      {
        p[i]= 1;
      }
      
      for(ll i=3 ; i <=1000000; i += 2){
            //if the current no. is not marked (its is prime)
            if(p[i]==1){
               //mark all the multiple of i as not prime
               for(ll j=i*i; j <= 1000000; j = j+i){
                    p[j]=0;
               }
            }
       
      }
        //special case
        p[2]=1;
        p[1]=p[0] =0;

 }

int main(){

    int n;
    cin>>n;
    int p[1000000] ={0};
    
    seive(p);
    for (int i = 0; i <= n; i++)
    {
        if (p[i] == 1)
        {
            cout<<i<<" ";
        }
        
    }
    

    return 0;
}