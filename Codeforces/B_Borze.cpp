/* 0 for . 
    1 for -.
    2 for --
    */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int main(){
ios::sync_with_stdio(0); 
cin.tie(0);
string s;
// vector<char> v;
vector<int> ans;
cin>>s;
int  i = 0;
while (s[i] != '\0')
{
    if (s[i] == '-')
    {
        (s[i+1] == '-') ? ans.push_back(2) : ans.push_back(1) ;
        i++;
    }
    else{
    ans.push_back(0);
    }
    i++;
}
for(int j : ans)
{
    cout<<j;
}
    return 0;
}