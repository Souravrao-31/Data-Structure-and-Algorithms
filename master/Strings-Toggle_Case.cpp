#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char a[1005];
    cin >> a;
    int max, sz = strlen(a);

    for (int i = 0; i < sz; i++)
    {
        if (a[i] >= 92)
            a[i] -= 32;
        else
            a[i] += 32;
    }
    cout << a;

    return 0;
}
