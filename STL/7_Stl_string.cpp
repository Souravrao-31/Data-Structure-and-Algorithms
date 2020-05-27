#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool comp(string a,string b){
    return a>b; // or return the value like return a.length()>b.length();
}
int main() {
    string s1("hello moto");
    string s2="again hello";
    string s3;
    getline(cin,s3);    //input
    cout<<s3<<endl;

    string arr[]={"Apple","orange","pineapple","mango","lemon"};
      sort(arr,arr+5,comp);    //it will sort the array string in alphabetic order
    for(int i=0;i<5;i++){
     cout<<arr[i]<<",";
    }

     cout<<"\n";

    cout<<s2.length()<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;
    for(int j=0;j<s3.length();j++){
        cout<<s3[j]<<"-";    //using s3[] it will iterate the char of j.
    }
  
}
