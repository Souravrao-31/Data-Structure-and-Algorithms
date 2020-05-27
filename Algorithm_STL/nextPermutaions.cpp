#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int arr[] ={10,20,30,40,50,60,70,80};
    int n =sizeof(arr)/sizeof(int);

    rotate(arr,arr+6,arr+n);

    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
    }
  cout<<endl;

    //apply same this on vectors

    vector <int> v{100,200,300,400,500,600,700};
    rotate(v.begin(),v.begin()+3,v.end());

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
   cout<<endl;
    //Next permuatation
    //it is similar to all methods
   vector<int> ve{1, 2, 3, 4};
   next_permutation(ve.begin(), ve.end());
   next_permutation(ve.begin(), ve.end());
   next_permutation(ve.begin(), ve.end());
   next_permutation(ve.begin(), ve.end());
 //for each permuatation it change
   //for each loop
   for(int x:ve){
       cout<<x<<" ";
   }



    
}