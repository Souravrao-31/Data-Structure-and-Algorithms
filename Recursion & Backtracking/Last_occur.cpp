#include <iostream>
using namespace std;

int fuc(int *arr, int n, int key)
{
    if (n == 0)
    {
        return -1;
    }
    //rec case
    
    int i = fuc(arr + 1, n - 1, key);
    if (i == -1)
    {
        if (arr[0] == key)
        {
            return 0;
        }
        else{
            return -1;
        }
    }
    return i + 1;
}
int main()
{
    int arr[] = {1, 5, 6,7, 4, 12, 7, 4, 8};
    int key = 7;
    int n = sizeof(arr) / sizeof(int);
    cout << fuc(arr, n, key);

    return 0;
}