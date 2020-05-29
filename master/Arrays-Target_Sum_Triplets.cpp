#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, target;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A, A + n);
    cin >> target;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (A[i] + A[j] + A[k] == target)
                {
                    cout << A[i] << ", " << A[j] << " and " << A[k] << endl;
                }
            }
        }
    }

    return 0;
}
