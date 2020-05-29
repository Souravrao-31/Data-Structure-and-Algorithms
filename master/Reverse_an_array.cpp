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
    for (int i = 0; i < t; i++)
    {
        cout << A[t - i - 1] << " ";
    }
    return 0;
}
