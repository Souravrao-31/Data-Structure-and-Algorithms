#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "  ";
        }

        for (int j = 0; j <= 2 * i; j++)
        {
            cout << abs(i - j) << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "  ";
        }

        for (int j = 0; j <= 2 * i; j++)
        {
            cout << abs(i - j) << " ";
        }
        cout << endl;
    }

    return 0;
}
