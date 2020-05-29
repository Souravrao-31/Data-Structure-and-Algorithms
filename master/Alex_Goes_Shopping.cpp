// @author: Abhimanyu Maurya

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

int main()
{
    int n, t, p, num;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    cin >> t;
    while (t--)
    {
        cin >> p >> n;
        int res = 0;
        for (auto &i : v)
            if ((p % i) == 0 and p >= i)
                res++;
        if (res >= n)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
