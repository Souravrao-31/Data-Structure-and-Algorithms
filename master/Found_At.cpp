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
    cin >> key;
    for (int i = 0; i < t; i++)
    {
        if (A[i] == key)
        {
            cout << i;
            exit(0);
        }
    }
    cout << -1;

    return 0;
}
