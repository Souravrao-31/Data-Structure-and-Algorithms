#include<iostream>
#include<string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string a,b,c;
    cin>>t;
    while (t--)
    {
        cin>>a>>b;
        c.resize(a.length());
        for (int i = 0; i < a.length(); i++)
        {
            if((a[i]-'0')!=(b[i]-'0')) 
                c[i]=(1+'0');
            else
                c[i]=(0+'0');
        }
        cout<<c<<'\n';
    }
    
    return 0;
}
