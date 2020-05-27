#include <iostream>
using namespace std;

int max_sumArray(int a[],int n){  // T(n)=O(n)
    int cs=0;
    int ms=0;
    for(int i=0;i<n;i++){   /* Kadane's algorithm */
     cs = cs + a[i];
     if(cs<0){
         cs=0; 
     }
     ms=max(cs,ms);
    }
    return ms;
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        
        cin>>n;
        int a[n];
        for(int j=0;j<n;j++){
           cin>>a[j];
        }
        int total = max_sumArray(a,n);
        cout<<total<<endl;
    }

return 0;
}
