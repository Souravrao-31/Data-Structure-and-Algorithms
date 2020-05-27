#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Finding subsets of given string
Input-"abc"
Output -" ",a,ab,abc,ac,b,,bc,c
*/

void fun(int n,char a[])
{

    int j = 0;

    while (n > 0)
    {
        int last_bit = (n & 1);
        if (last_bit == 1 )
        {
         cout<<a[j];
        }
        j++;
        n = n>>1;
    }
      cout<<endl;
}    

void print(char a[]){
  
   int n = strlen(a);
    for(int i=0; i < (1<<n); i++){
       fun(i,a);
    }
    return;
    
}

int main(){
    char a[100];
    cin>>a;
    print(a);

    return 0;
}