#include <iostream>
#include <cstring>
using namespace std;

void subsequence(char *in, char *out, int i, int j)
{
  
  //base case
  if(in[i] == '\0'){
      out[j] = '\0';
      cout<<out<<",";
      return;
  }

  //Rec case
  //1.Include current char

  out[j] = in[i];
  subsequence(in,out,i+1,j+1);

  //2.Exclude current char
  subsequence(in,out,i+1,j);

}
int main(){
    
    char in[100];
    cin>>in;

    char out[100];
    subsequence(in,out,0,0);
    return 0;

}