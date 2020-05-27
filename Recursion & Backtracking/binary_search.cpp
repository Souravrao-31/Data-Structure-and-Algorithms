#include <iostream>
using namespace std;

int binarySearch(int *a,int n,int key,int mid){

if(key==n){
    return -1;
}


if(a[mid] == key){
     return mid; 
}

else if(a[mid] < key){
    return binarySearch(a,mid+1,n,key);
}

}

int main()
{

int a[] ={1,3,4,6,8,10,14};
int n= sizeof(a)/sizeof(int);
int key =15;
int mid = n / 2;

cout<<binarySearch(a,n,key,0);

    return 0;
}