#include<iostream>
using namespace std;
/*
  Q =  1 2 1 3 3
  o/p = 2
*/
 //O(n) (1)
int main(){

    int n;
    cin>>n;

    int num;
    int ans=0;

    for(int i=0;i<n;i++){
        cin>>num;
        ans =ans ^ num;
    }
    cout<<ans<<endl;
    return 0;

}