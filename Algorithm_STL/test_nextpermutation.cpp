#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    vector<int> v;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }
    }
    next_permutation(v.begin(), v.end());
    for (auto x : v)
    {
        cout << x << " ";
    }
    return 0;
}