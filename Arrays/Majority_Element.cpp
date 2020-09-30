#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/
class Solution {
public:
     //O(N) O(N)
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> a;
        int c = 0;
        int f = 0;
        
        for(int b : nums){
            a[b]++;
        }
        for(auto d : a)
            if(d.second > c){
                c = d.second;
                f = d.first;
            };
        
        if(a[f] > nums.size()/2)  return f;
        else return -1;
         
    }

    //By sorting
    //O(nlogn + n)
     int majorityElement_II(vector<int>& nums){
        sort(nums.begin(), nums.end() );
        return nums[nums.size() / 2];
    }


         //Boyer moree voting
        //O(n) O(1)
    int majorityElement_III(vector<int>& nums){
        int idx = 0;
        int count = 1;

        for(int i=1;i<nums.size();i++){
            if(nums[idx] == nums[i]) count++;
            else count--;
            if(count == 0){  //reset candidate
                idx =i;
                count =1;
            }
        }

        return nums[idx];
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
    cout<<s.majorityElement(v)<<endl;
    cout<<s.majorityElement_II(v)<<endl;
    cout<<s.majorityElement_III(v);
        return 0;
}