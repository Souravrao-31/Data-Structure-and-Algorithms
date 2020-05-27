#include <iostream>
using namespace std;

int fun(int a[],int n,int key){

    int s = 0;
    int e = n - 1;
    int mid;

    while (s <= e)
    {
        mid = (s + e) / 2;

        if (a[mid] == key)
        {
            return mid;
        }

        else if (a[s] <= a[mid])
        { //search in both direction
            if(key >= a[s] and key <= a[mid]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        else
        {
           if(key >= a[mid] and key <= a[e]){
              s=mid+1;
           } 
           else
           {
               e=mid-1;
           }
           

        }
    }
    return -1;
}

int main(){
    int n,key;
    cin>>n;

    int a[10000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>key;
    cout<<fun(a,n,key);

    return 0;
}