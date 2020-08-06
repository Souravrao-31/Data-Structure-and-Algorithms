#include <bits/stdc++.h>
using namespace std;
int main(){
    int i;
    int n;
    cin>>n;

    int a[n+1];
    int cs=0;
    int ms=INT_MIN;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cs=cs+a[i]; 
        ms =max(cs,ms);
        
        if(cs<0){
            cs=0;
        }
    }
     cout<<"Maximum sum is "<< ms<<endl;
    return 0;
}