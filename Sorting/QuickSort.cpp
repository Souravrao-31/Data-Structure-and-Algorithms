#include<iostream>
using namespace std;

int partition(int *arr,int s,int e){

    //Inplace 
    int i=s-1;
    int j=s;

    int pivot =arr[e];   //pivot can be any element

    for(;j<=e-1;j++){
        if(arr[j] <= pivot){
          //merge the smaller
          i=i+1;
          swap(arr[i],arr[j]);
        }
        //expand the larger region
        j=j+1;
    }
    //place the pivot element in the correct
    swap(arr[i+1],arr[e]);
    return i+1;

}
void Sort(int *arr,int s,int e){
    //base case
    if(s >= e){
      return;
    }

    //recursive case
    int p=partition(arr,s,e);
    //left part
    Sort(arr,s,p-1);
    //right
    Sort(arr,p+1,e);
}

int main(){
    int n;
    cin>>n;
    int *arr =new int[n];

    for(int i=0;i<n;i++){
       cin>>arr[i];
    }
    Sort(arr,0,n-1);

    for(int i=0;i<=n-1;i++){
       cout<<arr[i]<<" ";
    }

    return 0;
}