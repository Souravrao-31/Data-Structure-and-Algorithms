// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;


long long toDec(long long a, long long base)
{
    if (a == 0)
        return a;
    return (a % 10) + toDec(a / 10, base) * base;
}

long long toBase(long long a, long long base)
{
    if (a == 0)
        return a;
    return (a % base) + toBase(a / base, base) * 10;
}
int main()
{
    long long g, d, n;
    cin >> g >> d >> n;
    cout << toBase(toDec(n, g), d);
    return 0;
}
