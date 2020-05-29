#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<bool> sieve(1000001,true);
    long a,b;
    int t,result;
    cin>>t;
    sieve[0]=sieve[1]=false;
    for (long i = 2; i*i <= 1000000; i++)
    {
        if (sieve[i]==true)
        {
            for (long j = i * i; j <= 1000000; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    while (t--)
    {
        result=0;
        cin>>a>>b;
        for (long i = a; i <= b; i++)
        {
            if (sieve[i] == true)
            {
                result++;

            }
            
        }
        cout<<result<<"\n";
    }  
    return 0;
}
