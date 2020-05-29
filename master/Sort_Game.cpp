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
    int x, n, t;
    cin >> x >> n;
    vector<pair<string, int>> data;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> t;
        if (t >= x)
            data.push_back(make_pair(s, t));
    }
    sort(data.begin(), data.end(), [](auto a, auto b) {if(a.second == b.second) return a.first<b.first; return a.second > b.second; });
    for (auto &i : data)
    {
        cout<<i.first<<" "<<i.second<<"\n";   
    }
    
    return 0;
}
