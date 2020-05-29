/*
* @Date    : 2020-04-22 16:02:56
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

signed main()
{
    int size, num;
    cin >> size;
    vector<int> v(size);
    for (auto &i : v)
        cin >> i;
    int element1 = 0, element2 = 0, count1 = 0, count2 = 0;
    for (auto &i : v)
    {
        if (i == element1)
            ++count1;
        else if (i == element2)
            ++count2;
        else if (count1 == 0)
            element1 = i, count1 = 1;
        else if (count2 == 0)
            element2 = i, count2 = 1;
        else
            --count1, --count2;
    }
    count1 = 0, count2 = 0;
    for (auto &i : v)
    {
        if (i == element1)
            ++count1;
        else if (i == element2)
            ++count2;
    }

    if (count1 > size / 3 or count2 > size / 3)
    {
        if (count1 > (size / 3))
            cout << element1 << " ";
        if (count2 > (size / 3))
            cout << element2 << " ";

    }
    else
        cout << "No Majority Elements";
    cout << '\n';
    return 0;
}
