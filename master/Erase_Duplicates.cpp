#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, num, prev = 0;
    cin >> t;
    cin >> num;
    cout << num << " ";
    prev = num;
    for (int i = 0; i < t - 1; i++)
    {
        cin >> num;
        if (prev != num)
        {
            cout << num << " ";
            prev = num;
        }
        else
            continue;
    }

    return 0;
}
