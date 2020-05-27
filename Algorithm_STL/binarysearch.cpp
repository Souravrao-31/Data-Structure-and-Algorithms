#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int arr[] ={20,30,40,40,40,90,110,120,200};
    int n =sizeof(arr)/sizeof(int);

    //search in asorted array
    int key;
    cin>>key;

    bool present = binary_search(arr,arr+n,key);

    if(present)
    {
        cout<<"Present";
        
    }
    else
    {
    cout<<"Absent";
    }
   /*
     two more things
     get the index of the element
     lower_bound(s,e,key) and upper bound(s,e,key) 
   */
  
cout<<endl;

    //Lower bound
   auto lb =lower_bound(arr,arr+n,90);
   cout<<(lb-arr)<<endl;

   //upper bound
   auto ub = upper_bound(arr, arr + n, 90);
   cout << (ub - arr) - 1<< endl;

   //frequency of element
   cout<<(ub - lb)<<endl;

   return 0;
}