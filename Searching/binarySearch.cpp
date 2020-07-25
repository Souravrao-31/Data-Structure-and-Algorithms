#include <iostream>
using namespace std;

int binarySearch(int a[],int n,int key){
int s=0;
int e=n-1;
int mid;

while(s<=e){
    mid= s + (e-s)/2;

    if(a[mid]==key){
        return mid;
    }

    else if(a[mid]>key){
        e=mid-1;
    }
    else
    {
        s=mid+1;  
    }
    
}
return -1;

}

int main(){
    int n,key;
    cin>>n;
    int a[1005];

    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }  
    cin>>key;
    int res=binarySearch(a,n,key);
   
   if (res==-1)
   {
       cout<<"not present";
   }
   else
   {
       cout<<res;
   }
   
    return 0;
}