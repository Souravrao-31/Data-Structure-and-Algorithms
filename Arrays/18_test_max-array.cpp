#include <iostream>
#include <algorithm>
int compare(int a,int b){
    return a<b;
}
using namespace std;
int main() {         //this will print the max element in the array
    int n;
    cin>>n;
   int arr[100];
   for(int i=0;i<n;i++){
       cin>>arr[i];  
   }
   sort(arr,arr+n,compare);
  
   cout<<arr[n-1];
   return 0;
}


