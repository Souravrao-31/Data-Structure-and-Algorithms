#include<iostream>
using namespace std;
const int M = 107;
int factMod107(int n)
{
    int fact=1;
    for (int i = 2; i <= n; i++)
    {
        fact = (fact*i)%M;
    }
    return fact;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,num,sum=0;
    cin>>t;
    while (t--)
    {
        cin>>num;
        sum = (sum+factMod107(num))%M;
    }
    cout<<sum;
    return 0;
}
