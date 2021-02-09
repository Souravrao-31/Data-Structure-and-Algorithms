#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        for(; j >= 0 && i >= 0; j--) {
            if(s[i] == t[j])   i--; 
        }
        if(i < 0) return true;
        return false;
    
      }
};    

int main() {
    string s;cin >> s;
    string t;cin >> t;

    Solution S;
    if(S.isSubsequence(s, t) ) cout<<"True";
    else cout<<"False";

}