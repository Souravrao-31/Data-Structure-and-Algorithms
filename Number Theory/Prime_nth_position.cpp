#include<bits/stdc++.h>
using namespace std;

 bool isPrime(int numm) {
    if (numm <= 1) {
        return false;
    }
 
    if(numm == 2){
        return true;
    }
 
    if (numm % 2 == 0) {
        return false;
    }
 
    int counter = 3;
 
    while ((counter * counter) <= numm) {
        if (numm % counter == 0) {
            return false;
        } else {
            counter +=2;
        }
    }
 
    return true;
}


int main(){
    int numPrimes = 1;
    int numm = 1;
    int N;cin>>N;
    while (numPrimes < N) {
        numm = numm + 2;
        if (isPrime(numm)) {
            numPrimes++;
        }
    }
    cout<<numm;
    return 0;
}