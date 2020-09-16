#include <iostream>
#include <cstring>
#include<set>
#include<string>
using namespace std;
// unique perm with lexicographical order
void permute(char *in,int i, set<string> &s){

 //Base case
 if(in[i] == '\0'){
        // cout<<in<<" ";
        string t(in);
        s.insert(t);
       return;
    }

  //Rec case
  for(int j=i; j < in[j] != '\0';j++){
  swap(in[i],in[j]);
   permute(in,i+1,s);
   
  //Backtracking - to restore original array
   swap(in[i],in[j]);

   }

}
int main(){

    char in[100];
    cin>>in;
    set<string> s;
    permute(in,0,s);
    //loop over the set

    for(auto str:s){
       cout<<str<<" ";
    }
    return 0;
}