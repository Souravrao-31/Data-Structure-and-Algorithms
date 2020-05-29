// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

int lastIndex(int a[], int r, int m)
{
    if (r < 0)
        return -1;
    if (a[r] == m)
        return r;
    return lastIndex(a, r - 1, m);
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
    cout << lastIndex(A, n - 1, m);

    return 0;
}
