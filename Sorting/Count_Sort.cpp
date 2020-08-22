#include<iostream>

using namespace std;

#define ll long long
void sort(int *arr,ll n){

    //largest in the array assuming no > 0
    int largest = -1;

    for(ll i=0;i<n;i++){
        largest = max(largest,arr[i]);
    }


    //create freq
    int *freq = new int[largest+1] {0};

    for(ll i=0;i<n;i++){
       freq[arr[i]]++;
    }

    //put the elements back into the array a by reading array
    ll j=0;

    for(ll i=0;i<largest;i++){
        while(freq[i]>0){
             arr[j] = i;
             freq[i]--;
             j++;
        }
    }  



}

int main(){
   

   ll n;
   cin>>n;

   int arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,n);

    for(ll i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}