#include <iostream>
using namespace std;
bool isMirrorInverse(string &A)
{
    int l = A.length();
    char B[l + 1];
    for (int i = 1; i <= l; i++)
    {
        B[l - (A[l - i] - '0')] = i + '0';
    }
    B[l] = '\0';
    return A == (string)B;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    string n;
    while (t--)
    {
        cin >> n;
        if (isMirrorInverse(n))
            cout << "true\n";
        else
            cout << "false\n";
    }

    return 0;
}
