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

    for (int i = 0; i < r; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < c; j++)
            {
                cout << a[i][j] << ", ";
            }
        }
        else
        {
            for (int j = c - 1; j >= 0; j--)
            {
                cout << a[i][j] << ", ";
            }
        }
    }
    cout << "END";
    return 0;
}
