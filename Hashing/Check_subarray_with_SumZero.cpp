#include<iostream>
#include<unordered_set>
using namespace std;

/*
4
2 5 -2 -3
yes

5
2 1 3 6 4
No
*/
bool checksubarray_withSumZERo(int *arr,int n){
   unordered_set <int> s;
    int pre =0;
    for(int i=0;i<n;i++){
        pre +=arr[i];
        //check if the sum was already present in set or not
        if(pre == 0 or s.find(pre) != s.end()){
           return true;
        }
        s.insert(pre);
    }
    return false;
}

int main(){
    
    int n;
    cin>>n;

    int *arr = new int[n];
    for(int i=0;i<n;i++){
       cin>>arr[i];
    }

    bool b = checksubarray_withSumZERo(arr,n);
    if(b==0){
      cout<<"No\n";
    }
    else{
        cout<<"yes\n";
    }
    //cout<<Funchecksubarray_withSumZERo(arr,n);
    return 0;
}