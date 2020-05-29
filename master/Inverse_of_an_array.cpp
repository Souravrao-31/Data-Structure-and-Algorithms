#include <iostream>
using namespace std;
bool prntMirrorInverse(char *A, int l)
{
    char B[l + 1];
    for (int i = 0; i < l; i++)
    {
        B[(A[i] - '0')] = i + '0';
    }

    B[l] = '\0';
    for (auto &i : (string)B)
    {
        cout<<i<<" ";
    }
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
    prntMirrorInverse(A,n);
    return 0;
}
