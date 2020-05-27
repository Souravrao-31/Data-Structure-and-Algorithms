#include<iostream>
using namespace std;

void dnf_sort(int arr[],int n){
     
    int low=0;
    int high=n-1;
    int mid=0;

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        if(arr[mid]==1){
            mid++;
        }
        if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }
   return;

}
int main(){
   int n;
   cin>>n;

   int arr[10000];

   for(int i=0;i<n;i++){
      cin>>arr[i];
   }
  dnf_sort(arr,n);

   for (int i = 0; i < n; i++)
   {
      cout<<arr[i]<<" ";
   }

    return 0;
}