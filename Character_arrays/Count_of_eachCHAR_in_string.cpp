#include <iostream>
using namespace std;

void sol(string S){
      
      int buffer[26] = {0};
      for(int i=0;i<S.length();i++){
          char c;
           buffer[S.at(i) - 'a']++;
      }
      for(int j=0;j<26;j++){
          cout<<buffer[j]<<" ";
      }
}

int main() {
    string S;
    getline(cin,S);

    sol(S);

}
