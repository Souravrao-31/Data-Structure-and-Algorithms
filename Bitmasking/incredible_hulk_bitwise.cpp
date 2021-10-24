#include<iostream>
using namespace std;

int computeBits(int n){
    
    int ans = 0;
    while(n>0){
        ans++;
        n = n&(n-1);
    }
    return ans;
    
}


int main() {
    int t,n;
    cin>>t;
    
    while(t--){
        cin>>n;
        cout<<computeBits(n)<<endl;
        
    }
    
        
	return 0;
}

