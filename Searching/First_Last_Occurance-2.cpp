#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
int binarySearch(vector<int>& nums, int target, bool searchFirst)
{
    int start=0, end=nums.size()-1, result=-1;
    while(start <= end)
    {
        int mid=(start+end)/2;
        if(nums[mid]==target)
        {
            result=mid;
            if(searchFirst) end=mid-1;
            else start=mid+1;
        }
        else if(nums[mid] < target) start=mid+1;
        else end=mid-1;
    }
    return result;
}

vector<int> searchRange(vector<int>& nums, int target) 
{
    vector<int> ans(2, -1);
    int first=binarySearch(nums, target, true);
    if(first==-1) return ans;
    int last=binarySearch(nums, target, false);
    ans[0]=first;
    ans[1]=last;
    return ans;
}
        
          
};


int main(){


  int n;cin>>n;
    vector<int> digits;

    for(int i=0;i<n;i++){
      int x; cin>>x;
      digits.push_back(x);
    }

     int target ; cin>>target;

    Solution s;
    

    vector<int> temp;
    temp = s.searchRange(digits,target);

    for(auto cp:temp){
        cout<<cp<<" ";
    }

}