#include<iostream>
using namespace std;

void bubblesort(int a[],int n){

/*
  here in this we are using iterative rec method

*/

//base case
if(n==1){
    return;
}

//recurssive case
for(int i=0;i<=n-2;i++){
     if(a[i]>a[i+1]){
        swap(a[i],a[i+1]);
     }

}
bubblesort(a,n-1);
}


void bubblesort_2(int a[],int j,int n){

    /*
    we will not use iterative method to solve this problem
    */
//base case
  if(n==1){

    return;
    }

if(j==n-1){

   return bubblesort_2(a,0,n);    //here j=0

}

if(a[j] > a[j+1]){
    swap(a[j],a[j+1]);
}
  bubblesort_2(a,j+1,n);
  return;

}


int main(){
    int a[1000];
    int n,j;
    cin>>n;

    for ( int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

 //bubblesort(a,n);
bubblesort_2(a,j,n);

 for (int i = 0; i < n; i++)
 {
     cout<< a[i]<<" ";
 }

    return 0;
}