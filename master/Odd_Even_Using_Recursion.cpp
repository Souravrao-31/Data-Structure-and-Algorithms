// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

// define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
FILE *fr = freopen("input.txt", "r", stdin);
FILE *fw = freopen("output.txt", "w", stdout);
#endif

void print(int n)
{
    if (n <= 0)
        return;
    if (n & 1)
    {
        cout << n << "\n";
        print(n - 1);
    }
    else
    {
        print(n - 1);
        cout << n << "\n";
    }
}

int main()
{
    int n;
    cin >> n;
    print(n);
    return 0;
}
