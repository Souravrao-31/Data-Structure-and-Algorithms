#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int row = 1; row <= t / 2 + 1; row++)
    {
        for (int col = 1; col <= t / 2 + 1 - row; col++)
        {
            cout << " \t";
        }

        for (int col = 1; col <= 2 * row - 1; col++)
        {
            cout << "*\t";
        }

        cout << endl;
    }

    for (int row = t / 2; row >= 1; row--)
    {
        for (int col = 1; col <= t / 2 + 1 - row; col++)
        {
            cout << " \t";
        }

        for (int col = 1; col <= 2 * row - 1; col++)
        {
            cout << "*\t";
        }

        cout << endl;
    }

    return 0;
}
