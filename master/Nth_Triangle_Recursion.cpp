// @author: Abhimanyu Maurya


#include <iostream>
using namespace std;


//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

int nTri(int n)
{
    if(n==1) return n;
    return n+nTri(n-1);
}

int main()
{
    int n;
    cin>>n;
    cout<<nTri(n);
    return 0;
}
