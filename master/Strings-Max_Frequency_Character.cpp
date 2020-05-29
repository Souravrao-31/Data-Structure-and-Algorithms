#include <iostream>
#include <cstring>
using namespace std;
int main()
{

    int freq[26] = {0};
    char a[1005];
    cin >> a;
    int max, sz = strlen(a);

    for (int i = 0; i < sz; i++)
    {
        freq[a[i] - 'a']++;
    }
    max=0;
    for (int i = 1; i < 26; i++)
    {
        if (freq[i] > freq[max])
            max = i;
    }
    char r = 'a' + max;
    cout << r;

    return 0;
}
