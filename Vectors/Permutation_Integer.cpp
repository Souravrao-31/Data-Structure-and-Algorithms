#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> fuck;
//         sort(nums.begin(), nums.end());
//         do{
//             fuck.push_back(nums);
//         }while(next_permutation(nums.begin(),nums.end()));
//         return fuck;
//     }
// };



// class Solution {
// public:
//     vector<vector<int> > permute(vector<int>& nums) {
//         vector<vector<int>>res;
//         vector<int>vec;
//         DFS(nums, 0, vec, res);
//         return res;
//     }
    
//     void DFS(vector<int>& nums, int pos, vector<int>& vec, vector<vector<int>>& res){
//         if(pos == nums.size()){
//             res.push_back(vec);
//             return;
//         }
//         for(int i = 0; i <= vec.size(); i++){
//             vec.insert(vec.begin() + i, nums[pos]);
//             DFS(nums, pos + 1, vec, res);
//             vec.erase(vec.begin() + i);
//         }
//         return;
//     }
// };

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        int loopLength = 1;
        for(int i = 1;i <= nums.size();i++){
            loopLength *= i;
         }
        for(int i = 0; i < loopLength ;i++){
            next_permutation(nums.begin(), nums.end());
            v.push_back(nums);
        }
        return v;
        
    }
};

int main(){
     vector<vector<int>> vs = { {1,2,3},
                                 {7,8,9}      };
    Solution s1;
   
    s1.permute(vs);

    return 0;
}