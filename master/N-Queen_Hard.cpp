#include <iostream>
#include <bitset>
using namespace std;
int count = 0;
bitset<30> col, d1, d2;

void solve(int r, int n)
{
    if (r == n)
    {
        count++;
        return;
    }
    for (int c = 0; c < n; c++)
    {
        if (!col[c] and !d1[r - c + n - 1] and !d2[r + c])
        {
            col[c] = d1[r - c + n - 1] = d2[r + c] = 1;
            solve(r + 1, n);
            col[c] = d1[r - c + n - 1] = d2[r + c] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    solve(0, n);
    cout << count;
    return 0;
}
