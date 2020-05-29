#include <iostream>
using namespace std;

void pat(int n)
{
    if (n == 0)
        return;
    pat(n - 1);
    for (size_t i = 0; i < n; i++)
    {
        cout << '*';
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    pat(t);
    // for (int row = 0; row < t; row++)
    // {
    //     for (int col = 0; col <= row; col++)
    //     {
    //         cout << '*';
    //     }
    //     cout << endl;
    // }

    return 0;
}
