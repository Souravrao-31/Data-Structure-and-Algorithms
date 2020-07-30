#include<iostream>
using namespace std;


int main(){
   
    long fib1=1, fib2=1;
    long sum=0; long result=0;

    while(result < 4000000){
       if((result % 2) == 0){
            sum += result;
       }
       result = fib1 + fib2;
       fib2 = fib1;
       fib1 = result;
    }
    cout<<sum;
 
    return 0;
}