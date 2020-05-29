#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, target;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cin >> target;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] + A[j] == target)
                cout << min({A[i], A[j]}) << " and " << max({A[i], A[j]}) << endl;
        }
    }

    return 0;
}
