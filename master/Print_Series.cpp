#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n1, n2, count = 0;
    cin >> n1 >> n2;
    for (int n = 1; count < n1; n++)
    {
        if ((3 * n + 2) % n2)
        {
            cout << 3 * n + 2 << endl;
            count++;
        }
    }

    return 0;
}
