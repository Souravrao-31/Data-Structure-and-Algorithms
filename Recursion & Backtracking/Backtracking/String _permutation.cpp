#include <iostream>
#include <cstring>
using namespace std;

void permute(char *in,int i){

 //Base case
 if(in[i] == '\0'){
    cout<<in<<" ";
       return;
    }

  //Rec case
  for(int j=i; j < in[j] != '\0';j++){
  swap(in[i],in[j]);
   permute(in,i+1);
   
  //Backtracking - to restore original array
   swap(in[i],in[j]);

   }

}
int main(){

    char in[100];
    cin>>in;

    permute(in,0);
    return 0;
}