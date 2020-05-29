#include <iostream>
using namespace std;
void toh(char a, char b, char c, int n)
{
    if (n == 1)
        cout << "Moving ring " << n << " from " << a << " to " << c << endl;
    else
    {
        toh(a, c, b, n - 1);
        cout << "Moving ring " << n << " from " << a << " to " << c << endl;
        toh(b, a, c, n - 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    toh('A', 'C', 'B', n);
    return 0;
}
