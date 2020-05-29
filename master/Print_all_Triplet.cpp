#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, target, sum;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A, A + n);
    cin >> target;
    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            sum = A[i] + A[l] + A[r];
            if (sum == target)
            {
                cout << A[i] << ", " << A[l] << " and " << A[r] << endl;
                l++;
            }
            else if (sum < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    return 0;
}
