#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i < 2 * t; i++)
    {
        cout << '*';
    }
    cout << endl;

    for (int row = t - 1; row > 1; row--)
    {
        for (int col = 1; col < t + row; col++)
        {
            if (col <= row)
                cout << '*';
        }
        for (int col = 1; col < 2 * (t - row); col++)
        {
            cout << ' ';
        }
        for (int col = 1; col < t + row; col++)
        {
            if (col <= row)
                cout << '*';
        }
        cout << endl;
    }

    for (int row = 1; row <= t - 1; row++)
    {
        for (int col = 1; col < t + row; col++)
        {
            if (col <= row)
                cout << '*';
        }
        for (int col = 1; col < 2 * (t - row); col++)
        {
            cout << ' ';
        }
        for (int col = 1; col < t + row; col++)
        {
            if (col <= row)
                cout << '*';
        }
        cout << endl;
    }

    for (int i = 1; i < 2 * t; i++)
    {
        cout << '*';
    }
    cout << endl;

    return 0;
}
