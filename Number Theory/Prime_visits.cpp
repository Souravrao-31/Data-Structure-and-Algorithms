#include <iostream>
using namespace std;

#define ll long long

/*
It will prime number from A to B.
11-20
o/p = 4
*/
void seive(int *p)
{ //O(n loglogn)

    //first mark all odd numbers
    for (int i = 3; i < 1000000; i += 2)
    {
        p[i] = 1;
    }

    for (ll i = 3; i <= 1000000; i += 2)
    {
        //if the current no. is not marked (its is prime)
        if (p[i] == 1)
        {
            //mark all the multiple of i as not prime
            for (ll j = i * i; j <= 1000000; j = j + i)
            {
                p[j] = 0;
            }
        }
    }
    //special case
    p[2] = 1;
    p[1] = p[0] = 0;
}

int main()
{

    
    int p[1000000] = {0};
    seive(p);

    int csum[1000000]={0};

    //precompute the primes upto an index i

    for(int i=1;i<=1000000;i++){
        csum[i]= csum[i-1]+p[i];

    }
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<csum[b] - csum[a-1]<<endl;
    }

    

    return 0;
}