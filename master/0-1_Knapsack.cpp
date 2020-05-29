#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, S, cw = 0, cp = 0;
    cin >> N >> S;
    int size[1001] = {0}, value[1001] = {0}, res[1001] = {0};
    for (int i = 1; i <= N; i++)
    {
        cin >> size[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> value[i];
    }
    int profit[1001][1001] = {0};

    for (int selected = 1; selected <= N; selected++)
    {
        for (int cap = 1; cap <= S; cap++)
        {
            if (size[selected] <= cap)
                profit[selected][cap] = max(profit[selected - 1][cap], profit[selected - 1][cap - size[selected]] + value[selected]);
            else
                profit[selected][cap] = profit[selected - 1][cap];
        }
    }

    cout << profit[N][S];
    return 0;
}