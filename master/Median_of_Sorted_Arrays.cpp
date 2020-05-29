// @author: Abhimanyu Maurya

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int a[n], b[n], c[2 * n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cin >> b[i];
//     }
//     int i = 0, j = 0, k = 0;
//     while (i < n and j < n)
//     {
//         if (a[i] < b[j])
//             c[k++] = a[i++];
//         else
//             c[k++] = b[j++];
//     }
//     while (i < n)
//     {
//         c[k++] = a[i++];
//     }
//     while (j < n)
//     {
//         c[k++] = b[j++];
//     }

//     cout << c[n - 1];
//     return 0;
// }

/*
* @Date    : 2020-05-13 17:27:40
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

signed main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;
    int i = 0, j = 0;
    while (n-- > 1)
    {
        if (a[i] <= b[j])
            i++;
        else
            j++;
    }
    cout << min(a[i], b[j]);
    return 0;
}
