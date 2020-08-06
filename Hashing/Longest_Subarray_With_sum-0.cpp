#include<iostream>
#include<unordered_map>
using namespace std;
/*
6
0 -1 1 2 -5 5
3

7
0 -1 1 2 -5 5 -2
7
*/
int checksubarray_withSumZERo(int *arr,int n){
    unordered_map<int, int> map;
    int pre=0;
    int len=0;

    for(int i=0;i<n;i++){
        pre += arr[i];
        if(pre == 0 ) len = max(len,i+1);

        if(map.find(pre) != map.end()){
           len = max(len, i - map[pre]);
        }
        else{
            //store the first occ
            map[pre] = i;
        }
    }
    return len;
}
int main(){
    
    int n;
    cin>>n;

    int *arr = new int[n+1];
    for(int i=0;i<n;i++){
       cin>>arr[i];
    }
   
   int b = checksubarray_withSumZERo(arr, n);
   cout<<b;
    
    return 0;
}