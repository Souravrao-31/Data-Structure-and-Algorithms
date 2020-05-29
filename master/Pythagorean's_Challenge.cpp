#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,A;
    cin>>n;
    bool flag;
    while (n--)
    {
        cin>>A;
        flag=false;
        for (int i = 0; i <= (int)sqrt(A); i++)
        {
            for (int j = i; j <= (int)sqrt(A); j++)
            {
                if ((i*i+j*j)==A)
                {
                    cout<<'('<<i<<','<<j<<") ";
                    flag=true;
                }
                
            }
        }
        if(flag) cout<<'\n';
    }
    return 0;
}
