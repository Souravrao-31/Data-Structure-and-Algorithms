#include<iostream>
using namespace std;
int main()
{
    int n,m,k,s;
    cin>>n>>m>>k>>s;
    char park[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>park[i][j];
        }   
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(s<k) break;
            if(park[i][j] == '.')
            {
                (j == m-1)? s-=2 : s-=3; 
            }
            else if(park[i][j] == '*') s+=4;
            else if(park[i][j] == '#') break;
        }   
    }
    if (s>=k)
    {
        cout<<"Yes\n"<<s;
    }
    else
    {
        cout<<"No";
    } 
    return 0;
}
