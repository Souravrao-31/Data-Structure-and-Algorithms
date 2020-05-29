#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int i;
    if(n==1) 
    {
        cout << "Not Prime";
        exit(0);
    }
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            break;
        }
    }
    if(i*i>n)
        cout<<"Prime";
    else
        cout<<"Not Prime";
    return 0;
}
