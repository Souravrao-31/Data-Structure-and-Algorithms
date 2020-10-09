#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//leetcode 15

/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
 Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
*/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // Input Length
        int numsSize = nums.size();

        //Edge Case
        if (numsSize == 0)
            return vector<vector<int>>();

        //Result Vector
        vector<vector<int>> result;

        //Sorting for Two pointer Technique
        sort(nums.begin(), nums.end());

        int l, r, sum;

        for (int i = 0; i < numsSize - 2; i++)
        {
            // Left Pointer to next element
            l = i + 1;
            // Right Pointer to last element
            r = numsSize - 1;

            // To avoid duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Checking triplets
            while (l < r)
            {
                sum = nums[l] + nums[i] + nums[r];

                // Comparison Cases
                if (sum > 0)
                {
                    r--;
                }
                else if (sum < 0)
                {
                    l++;
                }
                else
                {
                    // If sum equals to zero, Triplet found
                    // Add triplet to result vector
                    result.push_back(vector<int>{
                        nums[l], nums[i], nums[r]});

                    // Skipping duplicates
                    while (l < r && nums[l] == nums[l + 1])
                        l++;

                    // Skipping duplicates
                    while (r > l && nums[r] == nums[r - 1])
                        r--;

                    l++;
                    r--;
                }
            }
        }

        return result;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    Solution s;
   vector<vector<int>> temp = s.threeSum(v);
   for(int i=0;i<10;i++){
       for(int j=0;j<3;j++){
          cout<<temp[i][j]<<" ";
       }
       cout<<endl;
   }
}