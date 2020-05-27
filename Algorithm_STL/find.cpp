#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[] = {1,10,12,11,100,16};
    int len =sizeof(arr)/sizeof(int);

    int key;
    cin>>key;
    auto search =find(arr,arr+len,key);
    int index = search -arr;     //index will print 0x79655
                                 //so find the address search - arr
    if(index==len){
        cout<<"Not present";
    }
    else{
        cout<<index;
    }
    return 0;
} 