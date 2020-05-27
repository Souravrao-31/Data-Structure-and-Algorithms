#include<iostream>
#include<algorithm>
using namespace std;

int main()
{

    int a[] = {10,20,40,80,100,200,250,1000,5000};
    int n = sizeof(a) / sizeof(int);

    int key;
    cin >> key;

    bool present =binary_search(a,a+n,key);
    if(present){
        cout<<"Present";

    }
    else{
        cout<<"Absent";
    }

    return 0;
}