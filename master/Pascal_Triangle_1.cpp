// @author: Abhimanyu Maurya

#include <iostream>
#include <vector>
using namespace std;
#ifndef ONLINE_JUDGE
FILE *fr = freopen("input.txt", "r", stdin);
FILE *fw = freopen("output.txt", "w", stdout);
#endif
int main()
{
    int n, a[10] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int j = i - 1; j > 0; j--)
        {
            a[j] = a[j] + a[j - 1];
        }
        a[i - 1] = 1;
        for (int j = 0; j < i; j++)
        {
            cout << a[j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
