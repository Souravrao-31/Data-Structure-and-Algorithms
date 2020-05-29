// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

bool firstIndex(int a[], int l, int r, int m)
{
    if (l > r)
        return false;
    if (a[l] == m)
        return true;
    return firstIndex(a, l + 1, r, m);
}

int main()
{
    int n, A[100] = {0}, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cin >> m;
    if (firstIndex(A, 0, n - 1, m))
        cout << "true";
    else
        cout << "false";

    return 0;
}
