#include <iostream>
#include <unordered_map>
using namespace std;
/*
5
1 -1 5 -2 3
3

4
*/
int longest_withSumK(int *arr, int n,int k)
{
    unordered_map<int, int> map;
    int pre = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        pre += arr[i];
        
        if (pre == k)
            len = max(len, i + 1);
        if (map.find(pre - k) != map.end())
        {
            len = max(len, i - map[pre - k]);
        }
        else
        {
            map[pre] = i;
        }
    }
    return len;
}
int main()
{

    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    int b = longest_withSumK(arr, n,k);
    cout << b;

    return 0;
}