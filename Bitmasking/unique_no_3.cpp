#include <iostream>
using namespace std;

int main(){
     
     //array of fixed size is O(1) space.
     int cnt[64] ={0};

     int n,no;
     cin>>n;

    for(int i=0;i<n;i++){

        cin>>no;
        //update the count array
        int j=0;

        while(no>0){
             int last_bit=(no & 1);
             cnt[j] += last_bit;
             j++;
             no =no >> 1;

        }  

    }

     //iterate the array
     int p=1;
     int ans=0;
    for(int i=0;i<64;i++){
        cnt[i] %= 3;
        ans +=(cnt[i]*p);
        p =p<<1;

    }

    cout<<ans<<endl;
    return 0;
}