#include<iostream>
#include<set>
using namespace std;
/*
Set store unique element
and it print in sorted order
*/
int main(){
    int arr[] ={10,20,11,9,8,11,10,9};
    int n = sizeof(arr)/sizeof(int);

    set<int> s;
    for(int i=0;i<n;i++){
      s.insert(arr[i]);
    }
    s.erase(10);
    //print all elements
    for(set<int>::iterator it =s.begin();it != s.end();it++){
        cout<<*(it)<<" ";
    }
    return 0;
}