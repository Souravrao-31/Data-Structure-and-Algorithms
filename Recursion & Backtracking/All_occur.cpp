#include <iostream>
using namespace std;

void fuc(int *arr, int i,int n, int key)
{
    if(i == n){
       return;
    }
    if(arr[i] == key){
    cout<<i<<" ";
    }
    fuc(arr,i+1,n,key);
    
}
int store_occur(int *arr,int i,int n,int key,int *out,int j){
    //base case
    if (i == n)
    {
        return j;
    }
    if(arr[i] == key){
      out[j] == i;
      store_occur(arr,i+1,n,key,out,j+1);
    }
    //j remains unchanged
    return store_occur(arr,i+1,n,key,out,j);
}
int main()
{
    int arr[] = {1,2,3,7,4,5,6,7,10};
    int key = 7;
    int n = sizeof(arr) / sizeof(int);
    int out[100];
    //fuc(arr,0, n, key);

     cout<<endl;
     
     int count =store_occur(arr,0,n,key,out,0);

     cout << "Count "<<count<<endl;

      for (int k = 0; k < count; k++)
     {
        cout << out[k] << " ";
     }

    return 0;
}