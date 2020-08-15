#include<iostream>
using namespace std;


void merge(int arr1[],int n1, int arr2[], int n2,int arr3[]){
    /* declaring an array using dynamic allocation of memory. 
        Merged the given two arrays into this third output Array */
    //int* arr3 = new int [n1+n2];
    // Add your code below this line. Do not modify any other code.

       int i = 0, j = 0, k = 0; 
  
    // Traverse both array 
    while (i<n1 && j <n2) 
    { 
        // Check if current element of first 
        // array is smaller than current element 
        // of second array. If yes, store first 
        // array element and increment first array 
        // index. Otherwise do same with second array 
        if (arr1[i] < arr2[j]) 
            arr3[k++] = arr1[i++]; 
        else
            arr3[k++] = arr2[j++]; 
    } 
  
    // Store remaining elements of first array 
    while (i < n1) 
        arr3[k++] = arr1[i++]; 
  
    // Store remaining elements of second array 
    while (j < n2) 
        arr3[k++] = arr2[j++]; 


    
}    

int main(){
    
    int n1,n2;
    cin>>n1;
    int arr1[1000];

     for(int i=0;i<n1;i++){
         cin>>arr1[i];
     }
    cin>>n2;
    int arr2[1000];
     for(int i=0;i<n2;i++){
         cin>>arr2[i];
     }
        int arr3[n1+n2];
     merge(arr1,n1,arr2,n2,arr3);
   

      for (int i=0; i < n1+n2; i++) 
        cout << arr3[i] << " "; 

        return 0;
}