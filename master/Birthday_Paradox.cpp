/*
* @Date    : 2020-05-18 05:40:52
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

signed main()
{
    float probablity = 1, desiredProbablity;
    cin >> desiredProbablity;
    if (desiredProbablity == 1)
        cout << 366 << "\n";
    else
    {
        float numerator = 365, denominator = 365;
        while (probablity > 1 - desiredProbablity)
        {
            probablity = (probablity * numerator) / denominator;
            --numerator;
        }
        cout << denominator - numerator << '\n';
    }
    return 0;
}
