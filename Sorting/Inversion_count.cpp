#include <iostream>
using namespace std;
//invserion count

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;

    int temp[100];

    
}    

int Icount(int *arr, int s, int e)
{    
        if (s >= 0)
        {
            return 0;
        }
        //merge sort
        int mid = (s + e) / 2;

        int X = Icount(arr, s, mid);
        int Y = Icount(arr, mid + 1, e);
        int Z = ;
}

    int main()
    {
        int arr[100] = {1, 5, 2, 6, 3, 0};
        int n = sizeof(arr) / sizeof(int);

        return 0;
    }