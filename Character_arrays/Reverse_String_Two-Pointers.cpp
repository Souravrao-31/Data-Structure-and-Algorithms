
//344 Leetcode
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i;
        int j = s.size()-1;
        for(i = 0 ;i <j ;i++)
        {
            swap(s[i],s[j]);
            j--;
        }
    }
};