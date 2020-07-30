#include<iostream>
using namespace std;

#define ll long long int
void selection_sort(int a[],ll n){
   
   for(ll i=0;i<n-1;i++){
       //find out the smallest elements idx in the unsorted part
        int min_index=i;
       for(ll j=i;j<=n-1;j++){

          if(a[j]< a[min_index]){
             min_index=j;
         }
      }

      swap(a[i],a[min_index]);
   }

}


int main(){
    ll n;
    cin>>n;

    int a[n];

    for(ll i=0;i<n;i++){
      cin>>a[i];

    }
    
    selection_sort(a,n);

    for(ll i=0;i<n;i++){
      cout<<a[i]<<" ";
    }
    

    return 0;
}