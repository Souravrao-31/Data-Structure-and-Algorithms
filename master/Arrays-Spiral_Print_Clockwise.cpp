// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;
int main()
{
    int r, c;
    cin >> r >> c;
    int a[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    int rs = 0, re = r, cs = 0, ce = c;
    while (rs < re and cs < ce)
    {
        for (int i = cs; i < ce; i++)
        {
            cout << a[rs][i] << ", ";
        }
        rs++;
        for (int i = rs; i < re; i++)
        {
            cout << a[i][ce - 1] << ", ";
        }
        ce--;
        if (rs < re)
        {
            for (int i = ce - 1; i >= cs; i--)
                cout << a[re - 1][i] << ", ";
            re--;
        }
        if (cs < ce)
        {
            for (int i = re - 1; i >= rs; i--)
                cout << a[i][cs] << ", ";
            cs++;
        }
    }
    cout << "END";
    return 0;
}
