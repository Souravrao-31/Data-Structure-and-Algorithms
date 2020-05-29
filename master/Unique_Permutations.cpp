/*
* @Date    : 2020-04-14 20:05:09
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

set<vector<string>> p;

void permute(vector<string> &vs, int s, int e)
{
    if (s == e)
    {
        p.insert(vs);
        return;
    }
    for (int j = s; j <= e; j++)
    {
        swap(vs[s], vs[j]);
        permute(vs, s + 1, e);
        swap(vs[s], vs[j]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> vs(n);
    for (int i = 0; i < n; i++)
        cin >> vs[i];

    permute(vs,0,n-1);
    for (auto &i : p)
    {
        for (auto &j : i)
        {
            cout<<j<<" ";
        }
        cout << "\n";
    }
    return 0;
}
