// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

int Index(int a[], int l, int r, int m)
{
    if (l > r)
        return -1;
    if (a[l] == m)
        cout << l << " ";
    return Index(a, l + 1, r, m);
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
    Index(A, 0, n - 1, m);

    return 0;
}
