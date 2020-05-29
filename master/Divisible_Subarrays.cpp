#include<iostream>
#include<vector>
using namespace std;
int main()
{
    short test;
    cin>>test;
    while (test--)
    {
        long n,sum=0,item;
        cin>>n;
        vector<long>  counting(n,0);
        counting[0]=1;
        for (long i = 0; i < n; i++)
        {
            cin>>item;
            sum = (sum+item)%n;
            sum = (sum+n)%n;
            counting[sum]++;
        }
        long long result=0;
        for (long i = 0; i < n; i++)
        {
            long m = counting[i];
            result += (m*(m-1))/2;
        }
        cout<<result<<'\n';
    }    
    return 0;
}