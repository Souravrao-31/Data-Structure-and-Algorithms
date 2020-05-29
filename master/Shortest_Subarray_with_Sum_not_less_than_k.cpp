/*
* @Date    : 2020-04-27 01:00:39
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
#define int long long

int shortestSubarray(vector<int> &A, int K)
{
    deque<int> q;
    int n = A.size();
    int ans = n + 1;
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + A[i - 1];
    }
    for (int y = 0; y < n + 1; y++)
    {
        while (!q.empty() && prefix[y] <= prefix[q.back()])
            q.pop_back();

        while (!q.empty() && prefix[y] - prefix[q.front()] >= K)
        {
            ans = min(ans, y - q.front());
            q.pop_front();
        }
        q.push_back(y);
    }
    if (ans < n + 1)
        return ans;
    else
        return -1;
}

signed main()
{
    int t, k, res = -1;
    cin >> t;
    vector<int> v(t);
    for (auto &i : v)
        cin >> i;
    cin >> k;
    cout<<shortestSubarray(v,k);
    return 0;
}
