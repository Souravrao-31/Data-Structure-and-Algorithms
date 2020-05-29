#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int row = 1; row <= t; row++)
    {
        if (row == 1)
            cout << 1 << '\t';
        else
        {
            cout << row << '\t';
            for (int col = 1; col <= row - 2; col++)
            {
                cout << 0 << '\t';
            }
            cout << row << '\t';
        }

        cout << endl;
    }
    return 0;
}
