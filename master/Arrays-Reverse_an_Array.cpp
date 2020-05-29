#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, key;
    cin >> t;
    int A[t];
    for (int i = 0; i < t; i++)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= t; i++)
    {
        cout << A[t - i] << endl;
    }
    return 0;
}
