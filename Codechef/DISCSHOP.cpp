//https://www.codechef.com/ICPCTR01/problems/DISCSHOP

#include<iostream>
#include<string>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ans = stoi(s);
        for(int i=0;i<s.length();i++)
        {
           string temp = s;
           temp.erase(i, 1);
           ans  = min(ans, stoi(temp));
        }
        cout<<ans<<endl;
    }
    return 0;
}