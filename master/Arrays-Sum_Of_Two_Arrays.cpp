#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int n, m, i, j, carry = 0, temp, k;
    int a[1000], b[1000], c[1000];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", a + i);
    scanf("%d", &m);
    for (i = 0; i < m; i++)
        scanf("%d", b + i);
    i = n - 1;
    j = m - 1;
    if (n >= m)
        k = n - 1;
    else
        k = m - 1;
    while (i >= 0 && j >= 0)
    {
        temp = a[i] + b[j];
        c[k] = (temp % 10) + carry;
        carry = temp / 10;
        k--;
        i--;
        j--;
    }
    while (i >= 0)
    {
        temp = a[i];
        c[k] = (temp % 10) + carry;
        carry = temp / 10;
        k--;
        i--;
    }
    while (j >= 0)
    {
        temp = b[j];
        c[k] = (temp % 10) + carry;
        carry = temp / 10;
        k--;
        j--;
    }
    if (carry > 0)
        cout << carry << ", ";
    for (i = 0; i < n || i < m; i++)
        printf("%d, ", c[i]);
    printf("END");
}