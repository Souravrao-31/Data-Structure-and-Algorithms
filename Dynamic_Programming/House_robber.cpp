#include<iostream>
#include<vector>
using namespace std;



class Solution {
  
public:
     //O(n)
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int v1 = nums[0], v2 = max(v1,nums[1]);  //memoization
        for(int i=2;i<n;i++){
           int tmp = v2;
            v2 = max(v2,v1 + nums[i]);
            v1 = tmp;
        }
        return v2;
    }
    
    //Through recusrion we cannot  pass every cases TLE
    int rob_rec(vector<int>& nums, int n){
        if(n==0) return 0;
        if(n==1) return nums[0];
        return max(rob_rec(nums, n-1) , rob_rec(nums, n-2) + nums[n-1]  );
    }
    int rob_h(vector<int>& nums){
      return rob_rec(nums, nums.size());
    }
};

int main(){
    vector<int> v;
    int n;cin>>n;

    for(int i=0;i<n;i++){
       int x; cin>>x;
       v.push_back(x);
    }
   Solution s;
   cout<<s.rob(v);
   cout<<endl;
   cout<<s.rob_h(v);
}