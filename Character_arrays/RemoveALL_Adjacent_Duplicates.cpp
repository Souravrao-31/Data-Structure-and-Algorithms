#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*

1047

Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters,
 and removing them
 
Input: "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  
The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
*/
class Solution
{
public:
    string output(string s)
    {

        stack<char> st;
        string res = "";

        for (int i = s.length() - 1; i >= 0; i--)
        {
            char ch = s[i];

            if (!st.empty() and ch == st.top())
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }

        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};

int main()
{
    string S;
    cin>>S;

    Solution s;
    cout<< s.output(S);
    return 0;
}