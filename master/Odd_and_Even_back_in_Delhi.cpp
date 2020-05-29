#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,esum,osum,temp;
    cin>>n;
    string vehicle;
    while (n--)
    {
        esum=osum=0;
        cin>>vehicle;
        for (int i = 0; i < vehicle.length() ; i++)
        {
            temp = vehicle[i] - '0';
            if (temp%2==0)  
            {
                esum+=temp;
            }
            else
            {
                osum+=temp;
            }  
        }
        
        if((esum%4==0) || (osum%3==0))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    
    return 0;
}
