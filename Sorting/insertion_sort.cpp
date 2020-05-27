#include <iostream>
using namespace std;

void insertion_sort(int a[] ,int n){
    for (int i = 1; i <=n-1; i++)
    {
        int e =a[i];
        int j =i-1;

        while(j>=0 and a[i-1] > e){
            a[j+1]=a[j];
            j = j-1;
        }
        a[j+1] =e;
    }
    
}
int main(){
    int a[1000];
    int n,i;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
       cin>>a[i];
    }
    insertion_sort(a,n);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
    
    return 0;
}