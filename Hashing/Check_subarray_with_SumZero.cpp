#include<iostream>
#include<>
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
    <int> s;
    int pre =0;
    for(int i=0;i<n;i++){
        pre +=arr[i];
        
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
    return 0;
}