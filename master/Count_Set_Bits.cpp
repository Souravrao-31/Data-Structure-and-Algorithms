#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, num, count;
    cin >> t;
    while (t--)
    {
        cin >> num;
        count = 0;
        for (int i = 0; i < 32; i++)
        {
            if (num & 1)
            {
                count++;
            }
            num >>= 1;
        }
        cout << count << endl;
    }

    return 0;
}
