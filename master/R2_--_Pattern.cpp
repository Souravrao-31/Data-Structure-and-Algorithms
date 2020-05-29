#include <iostream>
using namespace std;

void print(int n)
{
    if (n < 1)
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    print(t);
    // for (int i = t%2?t:t-1; i >=1; i-=2)
    // {
    //     cout<<i<<endl;
    // }
    // for (int i = 2; i <= t; i+=2)
    // {
    //     cout<<i<<endl;
    // }

    return 0;
}
