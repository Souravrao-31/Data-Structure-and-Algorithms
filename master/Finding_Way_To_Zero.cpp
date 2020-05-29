/*
* @Date    : 2020-05-11 10:16:23
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

bool Check(vector<int> &arr, vector<bool> &reach, int size, int pos)
{
    if (pos < 0 or pos >= size or arr[pos] == -1)
        return false;
    if (reach[pos])
        return true;
    if (arr[pos] == 0)
        return reach[pos] = true;
    int t = arr[pos];
    arr[pos] = -1;
    bool l = Check(arr, reach, size, pos - t);
    bool r = Check(arr, reach, size, pos + t);
    if (l or r)
        return reach[pos] = true;
    return false;
}

int main()
{
    int n, p;
    cin >> n >> p;
    vector<int> arr(n);
    vector<bool> canReach(n);
    for (auto &i : arr)
        cin >> i;
    bool flag = Check(arr, canReach, n, p);
    if (flag)
        cout << "true\n";
    else
        cout << "false\n";
}