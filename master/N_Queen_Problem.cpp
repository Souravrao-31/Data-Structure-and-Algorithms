// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

// define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
FILE *fr = freopen("input.txt", "r", stdin);
FILE *fw = freopen("output.txt", "w", stdout);
#endif

int count = 0;

bool canPlace(bool board[11][11], int i, int j, int n)
{
    //check col
    for (int k = 0; k < i; k++)
    {
        if (board[k][j] == 1)
            return false;
    }
    //check diagonal
    for (int row = i, col = j; row >= 0 and col < n; row--, col++)
    {
        if (board[row][col])
            return false;
    }
    for (int row = i, col = j; row >= 0 and col >= 0; row--, col--)
    {
        if (board[row][col])
            return false;
    }
    return true;
}

bool countNQueens(bool b[11][11], int i, int n)
{
    // base case
    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (b[i][j])
                    printf("{%d-%d} ", i + 1, j + 1);
            }
        }

        count++;
        return false;
    }

    for (int k = 0; k < n; k++)
    {
        if (canPlace(b, i, k, n))
        {
            b[i][k] = 1;
            if (countNQueens(b, i + 1, n))
                return true;
            b[i][k] = 0;
        }
    }

    return false;
}

int main()
{
    int n;
    bool board[11][11] = {0};
    cin >> n;
    countNQueens(board, 0, n);
    cout << '\n'
         << count;
    return 0;
}
