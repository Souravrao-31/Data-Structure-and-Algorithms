#include <iostream>
#include <cstring>
using namespace std;
int A[1000001], B[1000001], C[1000001];
void countSort(int n, int mn, int mx)
{
    memset(C, 0, (n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        C[A[i] - mn + 1]++;
    }
    for (int i = 1; i <= mx; i++)
    {
        C[i] = C[i] + C[i - 1];
    }

    for (int i = n; i > 0; i--)
    {
        B[C[A[i] - mn + 1]] = A[i];
        C[A[i] - mn + 1]--;
    }
}
int main()
{
    int n, t, mn, mx;
    cin >> t;
    while (t--)
    {
        cin >> n >> mn >> mx;
        for (int i = 1; i <= n; i++)
        {
            cin >> A[i];
        }
        countSort(n, mn, mx);
        for (int i = 1; i <= n; i++)
        {
            cout << B[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
