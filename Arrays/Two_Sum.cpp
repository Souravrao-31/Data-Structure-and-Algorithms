#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //BruteForce approach O(n^2)
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int > v1;
        
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i] + nums[j] == target){
                    v1.push_back(i);
                    v1.push_back(j);
                    return v1;
                }
            }
        }
        return v1;
    }

    //O(n)
    vector<int> twoSum_2(vector<int>& nums, int target) {
        vector<int> v1(2);
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++){
            if(m.find(target - nums[i]) != m.end() ){
                v1[0]=m[target - nums[i]];
                v1[1]=i;
                return v1;
            }
            m[nums[i]]=i;
        }
        return {};
    }
     
     //another approach to solve this problem in O(n) time
     vector<int> twoSum_3(vector<int>& nums, int target) {
        
         unordered_map <int, int> m;
        for (int i{0}; i<nums.size(); i++){
            if (m.find(target-nums[i]) != m.end())
                return { m[target-nums[i]] , i };
            m[nums[i]] = i;
        }
         return {};      
        
    }
   
};


int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
       int x;cin>>x;
       v.push_back(x);
    }
    int target; cin>>target;
    Solution s;

    vector<int> temp1 = s.twoSum(v,target);
    if(temp1.size() > 0){
       cout<<temp1[0]<<" "<<temp1[1]<<endl;
    }

    vector<int> temp2 = s.twoSum_2(v,target);
    if(temp2.size() > 0){
       cout<<temp2[0]<<" "<<temp2[1]<<endl;
    }

    vector<int> temp3 = s.twoSum_3(v,target);
    if(temp3.size() > 0){
       cout<<temp3[0]<<" "<<temp3[1]<<endl;
    }
 

    return 0;
}