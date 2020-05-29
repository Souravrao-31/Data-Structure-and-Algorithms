#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    cout<<max({a,b,c,d,e});
    return 0;
}
