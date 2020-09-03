#include<bits/stdc++.h>
using namespace std;

/*
9
9 6 4 2 3 5 7 0 1
8
# 8 is the missing number
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        
        int sum_upto_n = 0;
        
        while(n != 0){
            sum_upto_n  +=n;
            n--;
        }
        
        int sum_of_elemnt = 0;
        
        for(int i:nums){
           sum_of_elemnt += i;
        }
        
        
        
        return sum_upto_n - sum_of_elemnt;
        
    }
};

//Method 2

      
 int missing(vector<int>& nums){

       int missing = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            missing ^= i ^ nums[i];
        }
        return missing;
 }
int main(){
   
   vector<int> v;
    int n;cin>>n;
   for(int i=0;i<n;i++){
      int x;cin>>x;
      v.push_back(x);
   }
   Solution s;
  cout<< s.missingNumber(v);
   cout<<missing(v);
    return 0;
}