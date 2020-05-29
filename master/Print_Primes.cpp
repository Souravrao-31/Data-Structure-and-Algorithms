#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<bool> sieve(1001, true);
    int t;
    cin >> t;
    sieve[0] = sieve[1] = false;
    for (long i = 2; i * i <= 1000; i++)
    {
        if (sieve[i] == true)
        {
            for (long j = i * i; j <= 1000; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    for (long i = 2; i <= t; i++)
    {
        if (sieve[i] == true)
            cout << i << "\n";
    }
    return 0;
}
