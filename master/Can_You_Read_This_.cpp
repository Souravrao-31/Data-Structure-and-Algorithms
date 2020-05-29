// @author: Abhimanyu Maurya


#include <iostream>
using namespace std;


//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);


int main()
{
    string s;
    cin>>s;
    for (int i = 0; s[i]!='\0'; i++)
    {
        cout<<s[i];
        if((int)s[i+1]<92) cout<<"\n";
    }   
    return 0;
}
