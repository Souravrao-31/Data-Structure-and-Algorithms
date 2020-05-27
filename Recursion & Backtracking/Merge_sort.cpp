#include <iostream>
using namespace std;



void merge(int *arr,int s,int e){
    int mid = (s + e) / 2;
    int i=s;
    int j=mid+1;
    int k=s;

    int temp[100];

    while(i <= mid && j <= e)
    {
      if(arr[i] < arr[j]){
        temp[k++] = arr[i++];
      }
      else{
         temp[k++] = arr[j++];
      }

    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while (j <= e)
    {
        temp[k++] = arr[j++];
    }
    //we need to copy all element to original array
    for(int i=s;i<=e;i++){
        arr[i]=temp[i];
    }


}

void mergeSort(int arr[],int s,int e){

//base class where we have element 1 or 0
if(s>=e){
return;
}
int mid =(s+e)/2;  //divide

//Recursively the array divide in two parts
mergeSort(arr,s,mid);
mergeSort(arr,mid+1,e);
//merge
merge(arr,s,e);

}

int main(){
    int n;
    cin>>n;
    int arr[100];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
     return 0;
}