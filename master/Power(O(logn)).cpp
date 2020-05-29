#include <iostream>
using namespace std;
// using recursion
// int calPow(int i, int j)
// {
//     if(j==0) return 1;
//     if (j % 2 == 1)
//         return i * calPow(i, j / 2) * calPow(i, j / 2);
//     else
//         return calPow(i, j / 2) * calPow(i, j / 2);
// }

// using bitmasking
int calPow(int i, int j)
{
    int res = 1;
    while (j > 0)
    {
        if (j & 1)
        {
            res *= i;
        }
        i = i * i;
        j = j >> 1;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x, n;
    cin >> x >> n;
    cout << calPow(x, n);
    return 0;
}
