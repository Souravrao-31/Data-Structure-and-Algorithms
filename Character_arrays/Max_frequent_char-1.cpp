#include <iostream>
using namespace std;

//this code is still on progress
//refer diff
int sol(string S){
      
      int buffer[26] = {0};
      for(int i=0;i<S.length();i++){
          char c;
           buffer[S.at(i) - 'a']++;
      }
      for(int j=0;j<26;j++){
          cout<<buffer[j]<<" ";
      }
       int max=buffer[0];
       for(int j=0;j<26;j++){
         
          if(buffer[j] > max)
            // max=buffer[j];
             max= j;
      }
      cout<<endl;
    return max;

}

int main() {
    string S;
    getline(cin,S);

    cout<<sol(S);



}
