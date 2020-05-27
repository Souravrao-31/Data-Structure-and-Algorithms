#include <iostream>
using namespace std;

int first_occurance(int a[],int n,int key){

    int s=0;
    int e=n-1;
    int ans=-1;

    while(s<=e){

        int mid = (s+e)/2;

        if(a[mid]==key){
         ans =mid;
         e=mid-1;
        }
        else if (a[mid] > key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }

    }

    return ans;
}

int Last_occurance(int a[],int n,int key){

    int s = 0;
    int e = n - 1;
    int ans = -1;

    while (s <= e)
    {

        int mid = (s + e) / 2;

        if (a[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (a[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return ans;
}

int main(){
   
   int a[] ={1,2,5,8,8,8,8,8,10,12,15,20};
   int n =sizeof(a)/sizeof(int);

   int key;
   cin >> key;

   cout<<first_occurance(a,n,key)<<endl;
   cout<<Last_occurance(a,n,key)<<endl;



    return 0;
}