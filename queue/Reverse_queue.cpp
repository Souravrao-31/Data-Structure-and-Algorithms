#include <bits/stdc++.h>
using namespace std;
int main() {
    stack<int> s;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
       int arr[10000];

       cin>>arr[i];
      int x=arr[i];
       s.push(x);
    }

    while(!s.empty()){
      cout<<s.top()<<" ";
      s.pop();
    }
    cout<<"END";
}
