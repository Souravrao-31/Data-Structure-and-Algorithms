// @author: Abhimanyu Maurya

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
    float n, w, tv, tw, res = 0;
    cin >> n >> w;
    vector<pair<float, float>> item;
    for (int i = 0; i < n; i++)
    {
        cin >> tv >> tw;
        item.push_back(make_pair(tv, tw));
    }

    sort(item.begin(), item.end(), [](auto a, auto b) { return a.first / a.second > b.first / b.second; });
    for (int i = 0; i < n; i++)
    {
        if (item[i].second < w)
        {
            res += item[i].first;
            w -= item[i].second;
        }
        else
        {
            res += (item[i].first * (w / item[i].second));
            break;
        }
    }
    cout << setprecision(1);
    cout << fixed << res;

    return 0;
}
