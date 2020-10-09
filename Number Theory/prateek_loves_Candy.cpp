#include <iostream>
#include <vector>

/*
Prateek recently graduated from college. To celebrate, he went to a candy shop and bought all the candies. The total cost was a number upto which there are n prime numbers (starting from 2). Since Prateek wants to minimize his cost, he calls you to help him find the minimum amount that needs to be paid. Being a student of Prateek bhaiya it is now your job to help him out :)

Input Format
First line contains a single integer denoting the number of test cases T. Next T lines contains a single integer N, denoting the number of primes required.


Constraints
T <= 10000

It is guaranteed that the answer does not exceed 10^6.

Output Format
Print the minimum cost that needs to be paid.

Sample Input
2
5
1
Sample Output
11
2
Explanation
In the first case there are 5 primes upto 11(2,3,5,7,11).
*/
using namespace std;
#define MAX 10000000
vector<bool>isPrime (MAX,true);
unsigned primearray[5761459];


void gen_primes(){
    isPrime[0]=isPrime[1]=false;
    for(unsigned i=2;i*i<=MAX;i++){
        if(isPrime[i]){
            for(unsigned j=i;j*i<=MAX;j++) isPrime[i*j]=false;
        }
    }
    unsigned idx = 1;
    primearray[0]=2;

    for(int i=3;i<=MAX;i+=2){
        if(isPrime[i]){
            primearray[idx++]=i;
        }     
    }
}

int main(int argc, char const *argv[])
{

    gen_primes();

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<primearray[n-1]<<endl;
    }
    return 0;
}