#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int main() 
{
    char a;
    cin >> a;
    int s=a;

    if(s>='a' && s<='z')   cout << "lowercase";  
    else if(s>='A' && s<='Z') cout << "UPPERCASE";      
    else  cout << "Invalid";
       
     return 0;
}