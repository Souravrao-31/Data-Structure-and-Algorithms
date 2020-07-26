#include <iostream>
using namespace std;
//Two ways to solve

char sol(int s){ //method 1
    if(s>='a' && s<='z')   return 'L';  
    else if(s>='A' && s<='Z') return 'U';      
    else  return 'I';
   
}
int main() {
   char x;
   cin>>x;
   if(isupper(x))
   {
       cout<<"U";
       
   }
   else if(islower(x))
   {
       cout<<"L";
       
   }
  else{
    cout<<"I";
  }
   //Function method
  int s=x;
  cout<<sol(s);
}
  