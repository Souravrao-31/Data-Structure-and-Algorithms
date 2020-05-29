#include <iostream>
using namespace std;

void bubbleSort(int A[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (A[i] > A[j])
                swap(A[i], A[j]);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    bubbleSort(A, n);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}
