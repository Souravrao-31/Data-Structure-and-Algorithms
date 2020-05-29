#include <iostream>
#include <cstring>
using namespace std;
int main()
{

    char a[1001];
    cin >> a;
    int s = strlen(a);
    bool flag = true;
    for (int i = 0; i < s / 2; i++)
    {
        if (a[i] != a[s - i - 1])
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "true";
    else
        cout << "false";

    return 0;
}
