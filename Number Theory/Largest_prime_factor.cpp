#include <iostream>
using namespace std;
/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/
int main() {

    long num;
    cin>>num;
    long newnum;
    newnum = num;
   long largestfact = 0;

   int  counter=2;

    while(counter * counter <= newnum){
       if(newnum % counter == 0){
           newnum = newnum/counter;
           largestfact = counter;
       }
       else{
           //counter++; or
           counter = (counter == 2) ? 3 : counter + 2;
       }
       
    }

    if(newnum > largestfact){
        largestfact= newnum;
    }

    cout<<largestfact;
}
