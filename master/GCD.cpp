#include<iostream>
using namespace std;
int main()
{
    long a,b,t;
    cin>>a>>b;
    while (a > 0 and b > 0)
    {
        t = a;
        a = b;
        b = t % a;
    }
    cout << (a ? a : b);
    return 0;
}
