#include<iostream>
#include<vector>
using namespace std;

/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/
class Solution {
public:
        //O(n)  O(1)
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i=0;
        for(int j=1;j<nums.size();j++){
           if(nums[i] != nums[j]){
               i++;
               nums[i] = nums[j];
           }
        }
        return ;
    }
};

int main(){
    Solution s;
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    cout<<s.removeDuplicates(v);
    return 0;
}