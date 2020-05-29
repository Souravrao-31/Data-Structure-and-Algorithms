#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        for (int j = 0; j < 2 * (n - i) - 1; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}
