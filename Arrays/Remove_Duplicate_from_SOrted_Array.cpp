#include<iostream>
#include<vector>
using namespace std;

/*
Let's look at one more example. This time, the result Array is smaller than the input Array! How's this going to work? Let's find out! Here's the problem description:

Given a sorted array, remove the duplicates such that each element appears only once.

Input: array = [1, 1, 2]
Output: [1, 2]
Input: array = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
Output: [0, 1, 2, 3, 4]
*/
class Solution {
public:
     //O(n)  O(1)
    vector<int> removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0 ) return nums;
        int uniqueNum=0;
        for(int i=0;i<nums.size();i++){
             if (i == 0 || nums[i] != nums[i - 1]) {
                  uniqueNum++;
               }

        }
         //cout<<uniqueNum;
         vector<int> result(uniqueNum);
         int positionInResult = 0;
        for (int i = 0; i < nums.size(); i++) {
        // Same condition as in the previous loop. Except this time, we can write
        // each unique number into the result Array instead of just counting them.
        if (i == 0 || nums[i] != nums[i - 1]) {
            result[positionInResult] = nums[i];
            positionInResult++;
        }
    }
    return result;
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
    vector<int> temp = s.removeDuplicates(v);
    int t = temp.size();
    for(int i=0;i<t;i++){
        cout<<temp[i]<<" ";
    }
    return 0;
}