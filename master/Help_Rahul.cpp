#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,key;
    cin>>n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cin>>key;
    auto result = find(arr.cbegin(),arr.cend(),key) - arr.cbegin();
    cout<<result;
    
    return 0;
}
