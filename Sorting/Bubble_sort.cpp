#include <iostream>
using namespace std;

void bubble_sort(int a[],int n){

    //N-1 large elements to the end
    for(int i=1;i<= n-1;i++){
       
       //Pairing Swapping in the unsorted of the array
       for(int j=0;j <= (n-i-1);j++){
           if(a[j] > a[j+1]){
              swap(a[j],a[j+1]);
           }

       }
    }


}

int main(){

    int n,key;
    int a[4];

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    bubble_sort(a,n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i]<<" ";
    }

   
    return 0;
}