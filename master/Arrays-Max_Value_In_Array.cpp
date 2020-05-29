#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, max, tmp;
    cin >> t >> max;
    for (int i = 0; i < t - 1; i++)
    {
        cin >> tmp;
        if (tmp > max)
            max = tmp;
    }
    cout << max;

    return 0;
}
