#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a = 0, b = 1, c = a, i = 0;
    cin >> n;
    while (i < n)
    {
        a = b;
        b = c;
        c = a + b;
        i++;
    }
    cout << c << '\n';
    return 0;
}
