#include <iostream>
using namespace std;

int trapWater(int a[], int n)
{
    int *left = new int[n];
    int *right = new int[n];

    left[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(a[i], left[i - 1]);
    }

    right[n - 1] = a[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(a[i], right[i + 1]);
    }

    int water = 0;
    for (int i = 0; i < n; i++)
    {
        water += min(left[i], right[i]) - a[i];
    }

    return water;
}
int main(){
    int a[100];
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<trapWater(a,n);
    return 0;
}