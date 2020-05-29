#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    bool flag = true;
    int esum = 0, osum = 0;
    while (n > 0)
    {
        if (flag)
            osum += n % 10;
        else
            esum += n % 10;
        flag = not flag;
        n /= 10;
    }
    cout << osum << '\n'
         << esum;
    return 0;
}
