#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

/*
Ramu has an array of strings. He want to find a string s such that it is a concatenation of sub-sequence of given array and have unique characters.Since,he has just started coding so he needs your help.
A sub-sequence of an array is a set of elements that can be obtained by deleting some elements(posssibly none) from the array and keeping the order same.
Print the maximum possible length of s

Input Format
The first line of input contains an interger n -the length of array.Next n lines contains the element(strings) of the array

Constraints
1 <= n <= 18, 1 <= arr[i].length<= 26

Output Format
Print one integer - the maximum length of s.

Sample Input
3
ab
cd
ab
Sample Output
4
*/

int Fun(vector<string> v, int i, string s)
{
    // Base case
    if (i == v.size())
    {

        if (s.length() > 26)
        {
            return 0;
        }

        int freq[26] = {0};

        for (int k = 0; k < s.length(); k++)
        {
            if (freq[s[k] - 'a'] == 1)
                return 0;

            freq[s[k] - 'a']++;
        }
        return s.length();
    }

    // We can include the ith string
    int op1, op2;
    op1 = op2 = INT_MIN;
    if (s.length() + v[i].length() <= 26)
    {
        op1 = Fun(v, i + 1, s + v[i]);
    }
    // We can exclude it
    op2 = Fun(v, i + 1, s);
    return max(op1, op2);
}

int UniqueString(vector<string> &v)
{
    return Fun(v, 0, "");
}

int main()
{
    vector<string> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    cout << UniqueString(v) << endl;

    return 0;
}