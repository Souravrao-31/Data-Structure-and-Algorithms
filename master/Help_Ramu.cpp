// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;
#ifndef ONLINE_JUDGE
FILE *fr = freopen("input.txt", "r", stdin);
FILE *fw = freopen("output.txt", "w", stdout);
#endif
int main()
{
    int test, c1, c2, c3, c4, r, c, rcost, ccost, t;
    cin >> test;
    while (test--)
    {
        cin >> c1 >> c2 >> c3 >> c4;
        cin >> r >> c;
        int tmpres = 0;
        for (int i = 0; i < r; i++)
        {
            cin >> t;
            tmpres += min(t * c1, c2);
        }
        rcost = min(tmpres, c3);
        tmpres = 0;
        for (int i = 0; i < c; i++)
        {
            cin >> t;
            tmpres += min(t * c1, c2);
        }
        ccost = min(tmpres, c3);
        cout << min(ccost + rcost, c4) << "\n";
    }

    return 0;
}
