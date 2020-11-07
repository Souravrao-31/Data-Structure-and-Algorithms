#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int num[7]={11,22,33,44,55,66,77};
    for(int a:num)
      cout<<a<<",";
    
    cout<<endl;
   
   for(int &a:num)
       a=11;

    for(int a:num)
    cout<<a<<",";   
}
