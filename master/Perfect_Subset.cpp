#include <iostream>
using namespace std;
#define ll unsigned long long
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            if (!(A[i] & A[j]))
                count += 2;
        }
    }
    cout << count;

    return 0;
}
