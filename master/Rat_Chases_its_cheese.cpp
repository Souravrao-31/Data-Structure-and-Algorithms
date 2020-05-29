#include <iostream>
#include <cstring>
using namespace std;
bool res[11][11] = {0};
char maze[11][11];
int n, m;
bool ratInMaze(int i, int j)
{
    // if considering for path return false
    if (res[i][j] == 1)
        return false;
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
        res[m - 1][n - 1] = false;
        return true;
    }

    if (i > m - 1 or j > n - 1 or j < 0 or i < 0)
        return false;
    if (maze[i][j] == 'X')
        return false;
    res[i][j] = 1;

    if (ratInMaze(i + 1, j) or ratInMaze(i - 1, j) or ratInMaze(i, j + 1) or ratInMaze(i, j - 1))
        return true;
    res[i][j] = 0;
    return false;
}

int main()
{

    cin >> m >> n;

    memset(maze, -1, sizeof(maze));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    if (!ratInMaze(0, 0))
        cout << "NO PATH FOUND";

    return 0;
}
