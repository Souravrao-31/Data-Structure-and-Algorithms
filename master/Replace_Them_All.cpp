#include<iostream>
#include<string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    for (auto &i : s)
    {
        if((i-'0')==0)
            i=(5+'0');
    }
    cout<<s;
    return 0;
}
