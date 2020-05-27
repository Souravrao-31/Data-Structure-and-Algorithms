#include <iostream>
using namespace std;

int fibon(int n){
  if(n==0 || n==1){
    return n;
  }

 int a1=fibon(n-1);
 int a2=fibon(n-2);
  return a1 + a2;

}

int main(){
    int n;
    cin>>n;
    
  cout<<fibon(n);

    return 0;
}