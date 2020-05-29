#include <iostream>
#include <cmath>
using namespace std;
#define mx 100
bool canPlace(int s[mx][mx], int i, int j, int num, int n)
{
    for (int it = 0; it < n; it++)
    {
        if (s[it][j] == num or s[i][it] == num)
            return false;
    }
    int sq = sqrt(n);
    int a = (i / sq) * sq;
    int b = (j / sq) * sq;
    for (int i = a; i < a + sq; i++)
    {
        for (int j = b; j < b + sq; j++)
        {
            if (s[i][j] == num)
                return false;
        }
    }
    return true;
}

bool sudokuSolver(int s[mx][mx], int i, int j, int n)
{
    //base if result found
    if (i == n)
    {
        //print sol
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << s[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    // if row is solved goto next
    if (j == n)
        return sudokuSolver(s, i + 1, 0, n);
    //if filled dont change
    if (s[i][j] != 0)
        return sudokuSolver(s, i, j + 1, n);

    for (int num = 1; num <= n; num++)
    {
        if (canPlace(s, i, j, num, n))
        {
            //assume
            s[i][j] = num;
            if (sudokuSolver(s, i, j + 1, n))
                return true;
            //backtrack
            s[i][j] = 0;
        }
    }

    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, sudoku[mx][mx] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> sudoku[i][j];
        }
    }
    sudokuSolver(sudoku, 0, 0, n);
    return 0;
}
