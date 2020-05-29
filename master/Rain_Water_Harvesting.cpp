// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;
int main()
{

    int n;
    cin >> n;
    int A[n], lm[n], rm[n], t;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    lm[0] = 0;
    for (int i = 1; i < n; i++)
    {
        lm[i] = max(lm[i - 1], A[i - 1]);
    }

    rm[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        rm[i] = max(rm[i + 1], A[i + 1]);
    }
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        t = min(rm[i], lm[i]) - A[i];
        if (t > 0)
            res += t;
    }
    cout << res;
    return 0;
}
