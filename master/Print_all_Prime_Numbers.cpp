#include<iostream>
bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
using namespace std;
int main()
{

    int num;
    cin>>num;
    if(num>=2)
    {
        cout<<2;
    }
    if(num>2)
    {
        for (int i = 3; i <= num; i++)
        {
            if (isPrime(i))
                cout<<", "<<i;
        }
    }

    return 0;
}
