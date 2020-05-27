#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    cout<<s<<endl;
    int len=s.length();
    cout<<len<<endl;
   int n=len-1;
    for(int i=0;i<(len/2);i++)
    {
     swap(s[i],s[n]);
     n=n-1;
    }
    cout<<s<<endl;
}