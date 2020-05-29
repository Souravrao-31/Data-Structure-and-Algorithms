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
            cout << 1;
        else
        {
            cout << row - 1;
            for (int col = 1; col <= row - 2; col++)
            {
                cout << 0;
            }
            cout << row - 1;
        }

        cout << endl;
    }
    return 0;
}
