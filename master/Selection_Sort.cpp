// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

void selSortRec(int a[], int l, int r)
{
    if (l == r)
        return;
    for (int i = l; i < r; i++)
    {
        if (a[i] > a[i + 1])
            swap(a[i], a[i + 1]);
    }
    selSortRec(a, l, r - 1);
}

int main()
{
    int n, A[100] = {0}, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    selSortRec(A, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
