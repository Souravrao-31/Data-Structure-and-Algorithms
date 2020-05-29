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

bool boardprint(int num, int dice, char *path, char *ptr)
{
    if (num == 0 or dice == 0)
    {
        count++;
        *ptr = '\0';
        cout << path << " ";
        return true;
    }
    int less = min(dice, num);
    bool res[less + 1];
    for (int i = 1; i <= less; i++)
    {
        *ptr = i + '0';
        res[i] = boardprint(num - i, dice, path, ptr + 1);
    }
    int i = 1;
    while (!res[i])
        i++;
    if (i <= less)
        return true;

    return false;
}

int main()
{
    int n, d;
    cin >> n >> d;
    char path[100];
    boardprint(n, d, path, path);
    cout << '\n'
         << count;
    return 0;
}
