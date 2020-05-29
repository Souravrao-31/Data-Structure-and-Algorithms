#include <iostream>
using namespace std;
int main()
{

    char a[101], res[101];
    cin >> a;
    int i, j, k = 0, cnt;
    i = j = 0;

    while (a[i] != '\0')
    {
        j = i;
        cnt = 0;
        while (a[j] == a[i])
        {
            cnt++;
            j++;
        }
        cout << a[i];
        i = j;
    }
    return 0;
}
