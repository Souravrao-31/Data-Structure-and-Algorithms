#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;
/*
Input: s = "(abcd)"
Output: "dcba"

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
*/
string reverseParentheses(string s)
{
    int n = s.size();
    stack<char> st;
    int i = 0;
    while (i < n)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            queue<char> t;
            while (st.top() != '(')
            {
                t.push(st.top());
                st.pop();
            }
            st.pop();
            //cout<<st.top()<<endl;
            while (!t.empty())
            {
                st.push(t.front());
                t.pop();
            }
        }
        else
        {
            st.push(s[i]);
        }
        i++;
    }
    string ans = "";
    while (!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << reverseParentheses(s);
    return 0;
}

/*
Algorithm:
We have reverse the string between each paranthesis. For this we first put all the characters in the string in a stack, lets say 'st'. 
We push the characters in the stack till we get a closing paranthesis character, in which case we have to pop the characters out of the stack till we get an opening paranthesis, and push those characters in a queue.
Now, we pop out the opening paranthesis and pop out characters pushed in the queue and push them back into the stack. In this way we have pushed the characters back into the stack after reversing the characters between the paranthesis.
We repeat the above process till we have removed all the paranthesis from the stack. Then we put all the characters in the stack into a string and return that string.

Time Complexity:
Time Complexity of the above code is O(n), where n is the number of characters in the stirng.
*/