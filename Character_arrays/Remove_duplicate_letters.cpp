#include<iostream>
#include<vector>
using namespace std;

//leetcode 316
// Example 1:

// Input: "bcabc"
// Output: "abc"

// Input: "cbacdcbc"
// Output: "acdb"
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string st="";
        vector<int> vt(26,-1);
        vector<int> seen(26,0);
        for(int i=0;i<s.length();i++){
            vt[s[i]-'a']=i;
        }
        

        for(int i=0;i<s.length();i++){
            if(seen[s[i]-'a']++){
                //cout<<i<<endl;
                continue;
            }
            while(st.size()>0 && st.back()>s[i] && vt[st.back()-'a' ]>i){
                seen[st.back()-'a']=0;
                st.pop_back();
            }
            st.push_back(s[i]);   
            
        }
        
        return st;
    }
};
int main(){
    string s;
    cin>>s;
    Solution S;
    cout<<S.removeDuplicateLetters(s);
    return 0;
}