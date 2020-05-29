/*
* @Date    : 2020-04-14 20:47:50
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;


bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
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
