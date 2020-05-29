#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int A[t];
    for (int i = 0; i < t; i++)
    {
        cin >> A[i];
    }
    int max, min;
    max = min = A[0];
    for (int i = 1; i < t; i++)
    {
        if (A[i] > max)
            max = A[i];
        if (A[i] < min)
            min = A[i];
    }
    cout << max << "\n"
         << min;
    return 0;
}
