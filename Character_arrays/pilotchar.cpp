#include <iostream>
using namespace std;
int main(){

    char a[10][10]{{'a','b','c'},{'d','e','f','\0'}};    //null char
    cout<<a[0]<<endl;
    cout<<a[1]<<endl;

    char b[][100] ={"saurav" ,"not","where"};
    cout << b[0] << endl;
    cout << b[1] << endl;
    cout<<b[2]<<endl;


    //now to take input string in 2d char

    char c[100][100];

    int n;
    cin>>n;
  
    cin.get();
    for(int i=0;i<n;i++){
        cin.getline(c[i],100);
    }
    //print the strings
    for(int i=0;i<n;i++){
        cout<<c[i]<<endl;
    }
   
  //diff between int and char array
    int ar[]= {1,2,3};
    cout<<ar<<endl;     //int will print the address 

    char ar1[]={'a','b','c'};
    cout<<ar1<<endl;
    return 0;    // it will print abc
}