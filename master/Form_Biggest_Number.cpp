#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        string A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        sort(A, A + n, [&](string a, string b) { return a.append(b) < b.append(a); });
        for (int i = n - 1; i >= 0; i--)
        {
            cout << A[i];
        }
        cout << endl;
    }

    return 0;
}
