// @author: Abhimanyu Maurya

#include <iostream>
#include <cstring>
#include <set>
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

set<string> p;

void permute(char in[], int i)
{
    if (in[i] == '\0')
    {
        p.insert(in);
        return;
    }
    for (int j = i; in[j] != '\0'; j++)
    {
        swap(in[i], in[j]);
        permute(in, i + 1);
        swap(in[i], in[j]);
    }
}

int main()
{
    char s[15];
    cin >> s;
    permute(s, 0);
    for (auto &i : p)
    {
        cout << i << "\n";
    }
    return 0;
}
