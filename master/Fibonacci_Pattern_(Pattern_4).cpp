#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, a = 0, b = 1, c = 0;
    cin >> t;
    for (int row = 0; row < t; row++)
    {
        for (int col = 0; col <= row; col++)
        {
            cout << a << "\t";
            c = a + b;
            a = b;
            b = c;
        }
        cout << endl;
    }

    return 0;
}
