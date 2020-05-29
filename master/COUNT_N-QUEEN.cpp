#include <iostream>
using namespace std;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    bool board[11][11] = {0};
    cin >> n;
    countNQueens(board, 0, n);
    cout << count;
    return 0;
}
