// FOREST
// Problem link :https://hack.codingblocks.com/app/contests/1665/1711/problem
/*
4 5
0 1 1 0 1
0 1 0 1 0
0 0 0 0 1
0 0 1 0 0

2
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>
using namespace std;



int n, m;
int grid[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};



bool check(int r, int c)
{
    return (r >= 0 and r < n and c >= 0 and c < m and (grid[r][c] == 0));
}


void solve()
{

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                q.push({i, j});
        }
    }

    int ans = -1;
    while (!q.empty())
    {
        int x = q.size();
        for (int i = 0; i < x; i++)
        {
            pair<int, int> f = q.front();
            q.pop();
            int r = f.first;
            int c = f.second;

            for (int j = 0; j < 4; j++)
            {
                int r1 = r + dx[j];
                int c1 = c + dy[j];
                if (check(r1, c1))
                {
                    grid[r1][c1] = 1;
                    q.push({r1, c1});
                }
            }
        }
        ans++;
    }
    cout << ans << endl;
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    solve();
    return 0;
}
