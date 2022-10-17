#include<bits/stdc++.h>
using namespace std;

void findsubsets(int ind, vector<int> &nums, vector<int> &ds, int sum){
    ds.push_back(sum);
    for(int i=ind; i<nums.size();i++)
    {
        if(i!=ind && nums[i]==nums[i-1]) continue;
        sum+=nums[i];
        findsubsets(i+1,nums,ds,sum);
        sum-=nums[i];
    }
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);

    vector<int> ds;
    vector<vector<int>> ans;
    findsubsets(0,nums,ds,0);
    sort(ds.begin(),ds.end());
    for(auto it : ds){
            cout<<it<<" ";
        cout<<endl;
    }
}