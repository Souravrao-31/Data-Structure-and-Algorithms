/*
* @Date    : 2020-04-26 22:24:08
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;
string smallestSubsequence(string text)
{

    string str = "";
    vector<int> count(26, 0);
    vector<bool> used(26, false);
    for (auto i : text)
        count[i - 'a']++;
    for (auto i : text)
    {
        count[i - 'a']--;

        if (used[i - 'a'] == false)
        {

            while (str.length() > 0 && i < str.back() && count[str.back() - 'a'] > 0)
            {
                used[str.back() - 'a'] = false;
                str.pop_back();
            }

            str.push_back(i);
            used[i - 'a'] = true;
        }
    }
    return str;
}

int main()
{
    string given;
    cin >> given;
    cout << smallestSubsequence(given);
    return 0;
}
