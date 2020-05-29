// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

// define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
FILE *fr = freopen("input.txt", "r", stdin);
FILE *fw = freopen("output.txt", "w", stdout);
#endif

int count = 0;

bool prntPath(int i, int j, int r, int c, char *path, char *ptr)
{
    if (i > r or j > c)
        return false;
    //at final pos print path and backtrack
    if (i == r and j == c)
    {
        *ptr = '\0';
        cout << path << " ";
        count++;
        return false;
    }
    // go vertical
    *ptr = 'V';
    bool v = prntPath(i + 1, j, r, c, path, ptr + 1);
    *ptr = 'H';
    bool h = prntPath(i, j + 1, r, c, path, ptr + 1);
    if (v or h)
        return true;
    return false;
}

int main()
{
    int r, c;
    char res[100] = {0};
    cin >> r >> c;

    prntPath(0, 0, r - 1, c - 1, res, res);
    cout << "\n"
         << count;
    return 0;
}
