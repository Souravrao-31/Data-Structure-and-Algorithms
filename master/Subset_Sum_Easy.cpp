// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;
bool isAnySubsetSumZero(int a[], int n)
{
    int sum;
    for (int i = 1; i < 1 << n; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                sum += a[j];
        }
        if (sum == 0)
            return true;
    }
    return false;
}

int main()
{
    int t, n, A[5];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        if (isAnySubsetSumZero(A, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
