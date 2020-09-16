#include<bits/stdc++.h>
using namespace std;

/* leet code 216
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination 
should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/
class Solution {
    void dfs(int k,int n,  vector<vector<int> > &ans,   vector<int> &sub){
        
         if(sub.size()>k) return;           
        if(n==0 && sub.size()==k) {
            ans.push_back(sub);
            return;
        }
        
        for(int i = sub.empty() ? 1 : sub.back() + 1 ; i<=9; i++){
            sub.push_back(i);
            if(n-i >= 0){
                dfs(k,n-i,ans,sub);
            }
            sub.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> sub;
        dfs(k,n,ans,sub);
        return ans;
    }
};


// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]

int main(){

    int k,n;
    cin>>k>>n;
    Solution s;
    vector<vector<int>> temp =  s.combinationSum3(k,n);
    int p = temp.size();
    //cout<<" P size"<<p<<endl;
    for(int i=0;i<p;i++){
         for(int j=0;j<k;j++){
             cout<<temp[i][j]<<" ";
         }
         cout<<endl;
    }

    return 0;
}