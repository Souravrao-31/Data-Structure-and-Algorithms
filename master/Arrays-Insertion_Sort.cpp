#include <iostream>
using namespace std;

void insertionSort(int A[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1, key = A[i];
        while (j >= 0 and A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
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
    insertionSort(A, n);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
