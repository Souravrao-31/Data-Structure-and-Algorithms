#include <iostream>
using namespace std;

void antiSpiral(int a[][100], int R, int C)
{
    int startcol = 0;
    int startrow = 0;
    int endcol = C - 1;
    int endrow = R - 1;

    while (startrow <= endrow and startcol <= endcol)
    {

        for (int i = startrow; i <= endrow; i++)
        {
            cout << a[i][startcol] << " ";
        }
        startcol++;

        for (int i = startcol; i <= endcol; i++)
        {
            cout << a[endrow][i] << " ";
        }
        endrow--;

        if (endcol > startcol)
        {
            for (int i = endrow; i >= startrow; i--)
            {
                cout << a[i][endcol] << " ";
            }
            endcol--;
        }

        if (endrow >= startrow)
        {
            for (int i = endcol; i >= startcol; i--)
            {
                cout << a[startrow][i] << " ";
            }
            startrow++;
        }
    }
}

int main()
{

    int R, C;
    cin >> R >> C;

    int a[100][100];

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> a[i][j];
        }
    }

    antiSpiral(a, R, C);
}