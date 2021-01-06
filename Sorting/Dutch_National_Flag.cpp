#include<iostream>
#include<vector>
using namespace std;

//Leetcode 75
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size()-1;
        
        while(mid<=high){
            
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
            else{
              mid++;   
            }
        }
        
    }
};

int main(){
    int n;cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    Solution s;
    s.sortColors(nums);

    for(int i=0;i<n;i++){
       cout<<nums[i]<<" ";
    }
}