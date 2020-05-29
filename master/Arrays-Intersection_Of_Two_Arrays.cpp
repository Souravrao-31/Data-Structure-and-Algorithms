#include <iostream>
#include <algorithm>
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
    int B[t];
    for (int i = 0; i < t; i++)
    {
        cin >> B[i];
    }
    sort(A, A + t);
    sort(B, B + t);
    int i, j, cnt = 0, C[t];
    i = j = 0;
    while (i < t and j < t)
    {
        if (A[i] == B[j])
        {
            C[cnt++] = A[i];
            i++;
            j++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    if (cnt > 0)
    {
        cout << '[' << C[0];
    }
    for (int i = 1; i < cnt; i++)
    {
        cout << ", " << C[i];
    }
    cout << ']';

    return 0;
}
