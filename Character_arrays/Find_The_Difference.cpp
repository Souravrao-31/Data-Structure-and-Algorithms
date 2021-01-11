#include<bits/stdc++.h>
#include<string>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        
        const int N = 26;
        vector<int> count(N, 0);
        for(size_t p = 0; p < s.size(); p++)
        {
            ++count[s[p] - 'a'];
        }
        for(size_t p = 0; p < t.size(); p++)
        {
            --count[t[p] - 'a'];
        }
        for(int p = 0; p < N; p++)
        {
            if(count[p] < 0)
            {
                char x = 'a' + p;
                 return x;
            }
        }
        return '0';
    }
};

int main(){

    string str;
    string str2;
    cin>>str>>str2;
    
   Solution s;
   char sh = s.findTheDifference(str, str2);

   cout<<sh;

    return 0;
}