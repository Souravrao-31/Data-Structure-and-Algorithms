#include <bits/stdc++.h>
using namespace std;
int main() {
    unordered_map<string, int> mp;
    pair<string,int> p = make_pair("abc", 10);
    mp.insert(p);

    mp.insert(make_pair("def", 20));
    mp["ghi"] = 30;

    for(auto i: mp){
        cout<<i.first<<", "<<i.second<<endl;
    }

    if(mp.find("def") != mp.end()){
        cout<<"def found"<<endl;
    }
    else{
         cout<<"def not found"<<endl;
    }
    
}
