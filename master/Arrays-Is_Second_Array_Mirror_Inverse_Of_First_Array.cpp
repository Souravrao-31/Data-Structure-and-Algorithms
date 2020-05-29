#include <iostream>
using namespace std;
bool isMirrorInverse(char *A, int l, char *C)
{
    char B[l + 1];
    for (int i = 0; i < l; i++)
    {
        B[(A[i] - '0')] = i + '0';
    }
    B[l] = '\0';
    return (string)B == (string)C;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    char A[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    A[n] = '\0';

    char C[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> C[i];
    }
    C[n] = '\0';

    if (isMirrorInverse(A, n, C))
        cout << "true";
    else
        cout << "false";
    return 0;
}
