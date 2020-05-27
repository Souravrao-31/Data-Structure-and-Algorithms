#include <iostream>
using namespace std;
/*
    factorial (n!)
*/
int main()
{
    int n;
    cin >> n;

    int i, j, k;
    int a[500];
    int temp = 0;
    a[0] = 1;
    int m = 1;
    int x;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = a[j] * i + temp;
            a[j] = x % 10;
            temp = x / 10;
        }

        while (temp > 0)
        {
            a[m] = temp % 10;
            temp = temp / 10;
            m++;
        }
    }

    for (i = m - 1; i >= 0; i--)
    {
        cout << a[i];
    }
    return 0;
}
