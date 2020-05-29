// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

int main()
{
    int n, d, c = 0, r;
    cin >> n >> d;
    while (n > 0)
    {
        r = n % 10;
        if (r == d)
            c++;
        n /= 10;
    }
    cout << c;
    return 0;
}
