#include<iostream>
using namespace std;

/*
    (2N + 1)
   qns = 3 1 2 1
   o/p = 3 2

   it will not solve the data like 
    1 1 1 2 3 3 3
    bcoz xor will terminate the 2 ones but not all so this will not give a proper o/p.
    and also it will not print the 3 unique value
*/

int main(){

    int n;
    int a[100005];
    cin>>n;

    int res =0;
    int no;
    for(int i=0;i<n;i++){
        cin>>no;
        a[i]=no;
        res =res ^ no;
    }

    int temp=res;
    int pos=0;

    while((temp&1)!= 1){
     pos++;
     temp = temp>>1;

    }

     int mask=(1<<pos);
      
      int x=0;
      int y=0;
    
    for(int i=0;i<n;i++){
        if((a[i] & mask) > 0){
           x = x ^ a[i];
        }

     y =res ^ x;

     
    }

    //cout << min(x, y) << " " << max(x, y) << endl;
    cout<<x<<" "<<y;

   return 0;
}