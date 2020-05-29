#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,d,g,md,mg;
    int a[200]={0},b[200]={0};
    cin>>t;
    while (t--)
    {
        cin>>d>>g;
        for (int i = 0; i < d; i++)
        {
            cin>>a[i];
        }

        for (int i = 0; i < g; i++)
        {
            cin>>b[i];
        }
        
        md = *max_element(a,a+d);
        mg = *max_element(b,b+g);
        if(mg < md)
        {
            cout<<mg<<" Gautam\n";
        }
        else
        {
            cout<<md<<" Deepak\n";
        }
    }    
    return 0;
}
