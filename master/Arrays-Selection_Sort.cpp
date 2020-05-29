#include <iostream>
using namespace std;

void selectionSort(int A[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (A[min] > A[j])
                min = j;
        }
        swap(A[min], A[i]);
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
    selectionSort(A, n);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}
