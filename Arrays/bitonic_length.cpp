#include <iostream>
using namespace std;

int length(int a[], int n){

    int inc[n];
    int dec[n];
    int max;

    inc[0]=1;
    dec[n-1]=1;

    for(int i=1;i<n;i++){
        inc[i]=(a[i]>a[i-1]) ? inc[i-1] + 1:1;

    }
    for(int i=n-2;i>=0;i--){
    dec[i] =(a[i]>a[i+1]) ? dec[i+1]+1:1;

    }
    max=inc[0] + dec[0] -1;
    for(int i=0;i<n;i++){
        if(inc[i] + dec[i]-1 > max){
            max =inc[i] + dec[i] -1;
        }
    }

    return max;
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
        int total = length(a,n);
        cout<<total<<endl;
    
    }

    return 0;
}
