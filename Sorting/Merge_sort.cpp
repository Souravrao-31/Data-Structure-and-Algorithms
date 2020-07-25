#include <iostream>
using namespace std;

#define ll long long int

void merge(int *arr,int s,int e){
    ll mid = (s + e) / 2;
    ll i=s;
    ll j=mid+1;
    ll k=s;

    int *temp;
    temp = new int[e+1];

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
    for(ll i=s;i<=e;i++){
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
    ll n;
    cin>>n;
     int *arr;
     arr = new int[n];

    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    mergeSort(arr,0,n-1);

    for(ll i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
     return 0;
}