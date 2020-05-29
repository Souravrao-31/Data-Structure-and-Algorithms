#include <iostream>
using namespace std;
int bsearch(int A[], int l, int h, int key)
{
    int mid = (l + h) / 2;
    if (A[mid] == key)
        return mid;
    if (h > l)
    {
        if (A[mid] > key)
        {
            return bsearch(A, l, mid - 1, key);
        }
        else
        {
            return bsearch(A, mid + 1, h, key);
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, key;
    cin >> t;
    int A[t];
    for (int i = 0; i < t; i++)
    {
        cin >> A[i];
    }
    cin >> key;
    cout << bsearch(A, 0, t - 1, key);

    return 0;
}
