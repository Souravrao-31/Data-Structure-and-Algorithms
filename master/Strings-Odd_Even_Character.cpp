/*
* @Date    : 2020-04-12 00:09:14
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <iostream>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

int main()
{
    string s;
    cin >> s;
    int count = 1;
    for (auto &ch : s)
    {
        if (count & 1)
            ch++;
        else
            ch--;
        count++;
    }
    cout << s;
    return 0;
}
