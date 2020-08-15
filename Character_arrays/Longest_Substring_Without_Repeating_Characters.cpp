#include<iostream>
#include<set>
using namespace std;
/*
Longest Substring Without Repeating Characters
leetcode 3
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      
        if(s.size()==0) return 0;
        int n=s.size();
        int i=0,j=0,ans=0;
        set<char> st;
        while(i<n && j<n){
            if(st.find(s[j])==st.end()){
                st.insert(s[j++]);
                ans=max(ans,j-i);
            }
            else{
                st.erase(s[i++]);
            }
        }

        return ans;
    }
};

int main(){
    string str; cin>>str;
    Solution S;
    cout<<S.lengthOfLongestSubstring(str);

    return 0;
}