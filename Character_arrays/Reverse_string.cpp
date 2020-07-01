#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int k = 0, n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == ' ')
                continue;

            if (k != 0)
                s[k++] = ' ';

            int j = i;
            while (j < n && s[j] != ' ')
                s[k++] = s[j++];

            reverse(s.begin() + k - (j - i), s.begin() + k);
            i = j;
        }
        s.resize(k);
        reverse(s.begin(), s.end());
        return s;
    }
};
int main() {
    string s;
    getline(cin,s);

    Solution p;
    cout<<p.reverseWords(s);
}   
