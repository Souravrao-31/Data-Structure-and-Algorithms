// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

int main()
{
    int n, zero = 0, one = 0, t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if (t)
            one++;
        else
            zero++;
    }
    for (int i = 0; i < zero; i++)
        cout << '0' << " ";
    for (int i = 0; i < one; i++)
        cout << '1' << " ";

    return 0;
}
