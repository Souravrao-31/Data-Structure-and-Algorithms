#include<bits/stdc++.h>

using namespace std;

/*
You will be given an array containing only 0s, 1s and 2s. you have sort the array in linear time that is O(N) where N is the size of the array.

Input Format
The first line contains N, which is the size of the array. The following N lines contain either 0, or 1, or 2.

Constraints
1 <= N <= 10^6
Each input element x, such that x ∈ { 0, 1, 2 }.

*/
void sort(int *arr,int n){

  int start = 0, mid=0, end =n-1;

  while(mid <= end){
     if(arr[mid]==0){
       swap(arr[start],arr[mid]);
       start++;
       mid++;
     }
     else if(arr[mid]==1){
        mid++;
     }
     else{
         swap(arr[mid],arr[end]);
         end--;
     }

  }



}

int main(){
    

   int n;
   cin>>n;

   int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}