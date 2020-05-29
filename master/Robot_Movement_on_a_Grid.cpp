// @author: Abhimanyu Maurya

#include <iostream>
#include <cstring>
using namespace std;

int board[10][10];
int r, c, res;
int p1r, p1c, p2r, p2c, p3r, p3c;

bool count(int i, int j, int pos)
{
    if (i >= r or j >= c or i < 0 or j < 0)
        return false;
    if (board[i][j] != 0)
        return false;
    if (i == p1r and j == p1c and pos != (int)(r * c) / 4)
        return false;
    if (i == p2r and j == p2c and pos != (int)(r * c) / 2)
        return false;
    if (i == p3r and j == p3c and pos != (int)(3 * r * c) / 4)
        return false;

    if (i == 0 and j == 1 and pos == (r * c))
    {
        res++;
        return false;
    }

    board[i][j] = pos;
    bool up = count(i - 1, j, pos + 1);
    bool right = count(i, j + 1, pos + 1);
    bool down = count(i + 1, j, pos + 1);
    bool left = count(i, j - 1, pos + 1);
    if (up or down or left or right)
        return true;
    board[i][j] = 0;
    return false;
}

int main()
{
    int t, tc;
    cin >> t;
    tc = t;
    while (t--)
    {
        res = 0;
        cin >> r >> c;
        cin >> p1r >> p1c >> p2r >> p2c >> p3r >> p3c;
        memset(board, 0, sizeof(board));
        count(0, 0, 1);
        cout << "Case " << tc - t << ": " << res << endl;
    }
    return 0;
}
