#include<bits/stdc++.h>
using namespace std;

vector<int> primeSieve(int *p,int n){
     p[0]=p[1] = 0;
     p[2]=1;

     //let us mark all odd numbers as prime init
     for(int i=3;i<=n;i+=2){
          p[i]=1;
     }

      for(int i=3;i<=n;i+=2){
          
        if(p[i]){
            //mark all the multiples of that as not prime
            //optimisation take a jump of 2i starting from i*i
            for(int j=i*i; j<=n; j+=2*i){
                 p[j]=0;
            }
        }
    }
    vector<int> primes;
    primes.push_back(2);

    for(int i=3;i<=n;i+=2){
        if(p[i]==1){
            primes.push_back(i);
        }
    }
    return primes;
}

vector<int> factorize(int m,vector<int> &primes){
       
       vector<int> factors;
       factors.clear();

       int i=0;
       int p= primes[0];

       while(p*p<=m){
           if(m%p==0){
               factors.push_back(p);
               while (m%p==0)
               {
                 m = m/p;
               }
            }   
               //go to the next position
               i++;
               p = primes[i];
       }
       //
       if(m!=1){
           factors.push_back(m);
       }
       return factors;

}

int main(){

   int N = 1000000;
   int p[N] = {0};
   for(int i=0;i<N;i++){
       p[i] = 0;
   }
   vector<int> prime = primeSieve(p,100);

   int t;cin>>t;
   while(t--){
       int no;
       cin>>no;

       vector<int> factors = factorize(no, prime);

        for(auto f: factors)
           cout<<f<<" "<<endl;
        }

    return 0;
}