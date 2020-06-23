#include<iostream>
#include<cstring>

using namespace std;

int abs(int i, int j){
    if(i-j > 0){
    return i-j;
    }
    return j-i;
}
int main(){

    int arr[100000] = {0};
    int t; cin>>t;

    while(t--){
        memset(arr,0,sizeof arr);
        string name;
        int n,rank; 
        cin>>n;

        for(int i=0;i<n;i++){
           cin>>name>>rank;
           arr[rank]++;
        }
        
        //Greedy approach
        int actualrank = 1;
        int sum = 0;
        for(int i=1;i<=n;i++){
            while(arr[i]){
                sum += abs(actualrank, i);
                arr[i]--;
                actualrank++;
            }
        }

       cout<<sum<<endl;
    }
    return 0;
}