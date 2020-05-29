#include <iostream>
#include <cstring>
using namespace std;
bool res[1000][1000] = {0};
char maze[1000][1000];
int n, m;
bool ratInMaze(int i, int j)
{
    if (i == m - 1 and j == n - 1)
    {
        res[m - 1][n - 1] = true;
        for (int a = 0; a < m; a++)
        {
            for (int b = 0; b < n; b++)
            {
                cout << res[a][b] << " ";
            }
            cout << endl;
        }
        cout << endl;
        res[m - 1][n - 1] = false;
        return true;
    }

    if (i > m - 1 or j > n - 1)
        return false;
    if (maze[i][j] == 'X')
        return false;
    res[i][j] = 1;

    if (ratInMaze(i, j + 1) or ratInMaze(i + 1, j))
        return true;
    res[i][j] = 0;
    return false;
}

int main()
{

    cin >> m >> n;

    memset(maze, -1, sizeof(char) * 1000000);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    if (!ratInMaze(0, 0))
        cout << -1;

    return 0;
}
