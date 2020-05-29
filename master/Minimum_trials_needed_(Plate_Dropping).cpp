#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int dp[1005][1005];

int minTrials(int floors, int plates)
{
    if (plates == 1)
        return floors;
    if (floors == 1 || floors == 0)
        return floors;
    if (dp[floors][plates] != -1)
        return dp[floors][plates];
    int minn = INT_MAX;
    for (size_t i = 1; i <= floors; i++)
    {
        minn = min(minn, max(minTrials(i - 1, plates - 1), minTrials(floors - i, plates)));
    }
    return dp[floors][plates] = minn + 1;
}

int main()
{
    int t, floors, plates;
    cin >> t;

    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        cin >> plates >> floors;
        cout << minTrials(floors, plates) << "\n";
    }
    return 0;
}
