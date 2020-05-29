#include <iostream>
using namespace std;
int main()
{

    int i, j, n, ans = 0, sum = 0;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (j = 0; j < 32; j++)
    {
        sum = 0;
        for (i = 0; i < n; i++)
        {
            if ((1 << j) & a[i])
                sum++;
        }
        if (sum % 3 == 1)
        {
            ans += (1 << j);
        }
    }
    cout << ans;

    return 0;
}
