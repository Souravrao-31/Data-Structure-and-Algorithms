#include<iostream>
#include<set>
#include<climits>
using namespace std;

int main(){
    set< pair<int,int>> s;

    s.insert(make_pair(10,6));  //make pair

    s.insert(make_pair(31, 12));
    s.insert(make_pair(18, 2));
    s.insert(make_pair(12, 2));
    s.insert(make_pair(26, 6));
    s.insert(make_pair(2, 7));
    s.insert(make_pair(5, 6));

    s.erase(make_pair(5,6));
    s.insert(make_pair(5,4));
    
    auto it = s.lower_bound(make_pair(26,6));
    cout<<it->first<<","<<it->second<<endl;

    for(auto p:s){
      cout<<p.first<<" and "<<p.second<<endl;  //in sorted manner
    }

   //atleat greater than 10
    auto at = s.lower_bound(make_pair(10, INT_MAX));
    cout << at->first << "," << at->second << endl;
    cout << at->first << "," << at->second << endl;

    return 0;
}