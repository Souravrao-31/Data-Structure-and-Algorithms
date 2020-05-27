#include <iostream>
using namespace std;
int main() {
    int *p=new int(30);    //new operator
    cout<<*p<<endl;
    int *q=new int();
    cout<<*q<<endl;
  //initializing array 
    int *arr=new int[30];
    for(int i=0;i<30;i++){
        arr[i]=i;
    }
    for(int i=0;i<30;i++){
        cout<<arr[i]<<" ";
    }
         //delete memory in run time

    delete p;
    delete q;
    delete [] arr;
    

}
