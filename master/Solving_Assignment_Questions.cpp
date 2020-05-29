// @author: Abhimanyu Maurya

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

int main()
{
    int t, n, m, temp;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<int> a, b;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            a.push_back(temp);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> temp;
            b.push_back(temp);
        }
        int amax = *max_element(a.begin(), a.end());
        int bmax = *max_element(b.begin(), b.end());

        if (amax <= bmax)
            cout << amax << " Deepak\n";
        else
            cout << bmax << " Gautam\n";
    }

    return 0;
}
