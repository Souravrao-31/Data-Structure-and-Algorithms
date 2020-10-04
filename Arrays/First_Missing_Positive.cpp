#include<iostream>
#include<vector>
using namespace std;
/*
41 leetcode
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1

*/
class Solution {
public:
    //O(n) O(n)
    int firstMissingPositive(vector<int>& nums) {
     
        bool Contain_one = false;
        for(int x:nums){
            if(x==1){
                Contain_one = true;
                break;
            }
        }
        if(!Contain_one) return 1;
        int n = nums.size();
        if(n==1) return 2;
        
        for(int i=0;i<n;i++)
            if(nums[i]<=0 || nums[i] > n) nums[i] = 1;
        
        for(int i=0;i<n;i++){
            int x=abs(nums[i]);
            if(nums[x-1] > 0) nums[x-1]*= -1;
        }
            
        for(int i=0;i<n;i++){
            if(nums[i] > 0) return i+1;
        }
        
        return n+1;
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
    cout<<s.firstMissingPositive(v);
    return 0;
}