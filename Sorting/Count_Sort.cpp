#include<iostream>

using namespace std;

void sort(int *arr,int n){

    //largest in the array assuming no > 0
    int largest = -1;

    for(int i=0;i<n;i++){
        largest = max(largest,arr[i]);
    }


    //create freq
    int *freq = new int[largest+1] {0};

    for(int i=0;i<n;i++){
       freq[arr[i]]++;
    }

    //put the elements back into the array a by reading array
    int j=0;

    for(int i=0;i<largest;i++){
        while(freq[i]>0){
             arr[j] = i;
             freq[i]--;
             j++;
        }
    }  



}

int main(){
    int arr[] ={8,5,2,1,3,4,5,25,88,2,1,45,6,3,8,45,88};

    int n = sizeof(arr)/sizeof(int);

    sort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}