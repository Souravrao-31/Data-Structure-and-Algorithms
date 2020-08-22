#include<bits/stdc++.h>
using namespace std;
int countSetBits(int num){
    int count  = 0 ;
    while(num){
        num&= (num-1);
        count+=1;

    }
    return count;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int  a ,  b;
        cin >> a >> b;
        int ans = 0;
        for(int i =a ; i <=b ; i++){
            ans += countSetBits(i);
        }
        cout << ans<<"\n";
    }
}