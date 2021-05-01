#include<bits/stdc++.h>
using namespace std;


//Leetcode 409
// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

 

// Example 1:

// Input: s = "abccccdd"
// Output: 7
// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.
// Example 2:

// Input: s = "a"
// Output: 1
// Example 3:

// Input: s = "bb"
// Output: 2


class Solution {
public:
    int longestPalindrome(string s) {
        int result = 0;
        
        unordered_map<char, int> counts;
        for(char c: s) counts[c]++;
        
        bool odd_count = false;
        for(auto& c: counts){
            if(c.second % 2== 0) result += c.second;
            else{
                odd_count = true;
                result += c.second -1;
            }
        }
        
        if(odd_count) result++;
        return result;
    }
};

int main(){


}