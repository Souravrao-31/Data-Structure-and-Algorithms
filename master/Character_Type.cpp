#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char ch;
    cin >> ch;
    if (ch >= 'a' and ch <= 'z')
        cout << 'L';
    else if (ch >= 'A' and ch <= 'Z')
        cout << 'U';
    else
        cout << 'I';
    return 0;
}
