#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        
        int n = nums.size();
        k %= n;
        std::vector<int> buffer(k);
        for(int p = 0; p < k; p++){buffer[p] = nums[n - k + p];}
        for(int p = n - 1; p >= k; p--){nums[p] = nums[p - k];}
        for(int p = 0; p < k; p++){nums[p] = buffer[p];}
        return;
    }
};

/*
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
*/

int main(){
  int n;cin>>n;
 vector<int> v;
 for(int i=0;i<n;i++){
    int x;cin>>x;
    v.push_back(x);
 }

 int k;cin>>k;

 Solution s;
 
 s.rotate(v,k);

 for(int a:v){
    cout<<a<<" ";
 }
   

}