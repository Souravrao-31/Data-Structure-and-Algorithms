#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string x, string y)
{

    string xy = x.append(y);

    string yx = y.append(x);

    return xy < yx;
}

int main()
{
    int t, n;
    cin >> t;    //test case

    while (t--)
    {
        int n, k;
        string c;
        vector<string> arr;

        cin >> n;     
        for (int i = 0; i < n; i++)
        {
            cin >> c;
            arr.push_back(c);
        }

        sort(arr.begin(), arr.end(), compare);

        for (auto k = arr.begin(); k != arr.end(); k++)
        {
            cout << (*k);
        }
        cout << endl;
    }
}
