// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

bool isSorted(int a[], int l, int r)
{
    if (l == r)
        return true;
    if (a[l] > a[l + 1])
        return false;
    return isSorted(a, l + 1, r);
}

int main()
{
    int n, A[100] = {0}, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    if (isSorted(A, 0, n - 1))
        cout << "true";
    else
        cout << "false";

    return 0;
}
