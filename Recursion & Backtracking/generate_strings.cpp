#include<iostream>
using namespace std;

void f(char *in,char *out,int i,int j){
    //base class
    if(in[i] =='\0'){
      out[j] = '\0';
      cout<<out<<endl;
      return;
    }

    //rec case
    //one digit at time
    int digit = in[i] - '0';
    char ch = digit + 'A' - 1;
    out[j] = ch;
    f(in ,out,i+1,j+1);

    //two digit at time
    if(in[i+1] != '\0'){
       int secondDigit = in[i+1] - '0';
       int no =digit * 10 + secondDigit;
        if(no <= 26){
        ch = no + 'A' -1;
        out[j] = ch;
        f(in ,out,i+2,j+1);
        }

    }
    return;
}

int main(){

    char in[1000];
    cin>>in;

    char out[1000];

    f(in,out,0,0);
    return 0;
}

