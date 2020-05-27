#include<iostream>
#include <algorithm>
using namespace std;

int main(){
    int a=10;
    int b=20;

    swap(a,b);
    //swapped
    cout<<a<<" and "<<b;
    cout<<endl;

    //maximum and minimum
    int maxi =max(a,b);
    cout<<maxi<<endl;
    cout<<min(a,b)<<endl;

    //reverse
    int arr[] = {1,2,3,4,5};
    reverse(arr, arr + 4);
    int n=sizeof(arr)/sizeof(int);
    
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


    return 0;

}