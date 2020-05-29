#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, num = 1;
    cin >> t;

    for (int row = 0; row < t; row++)
    {
        for (int col = 0; col <= row; col++)
        {
            cout << num++ << "\t";
        }
        cout << "\n";
    }

    return 0;
}
