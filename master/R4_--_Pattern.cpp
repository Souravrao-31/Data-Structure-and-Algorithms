// @author: Abhimanyu Maurya


#include <iostream>
using namespace std;


//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

void pat(int n)
{
    if(n==0) return;
    pat(n-1);
    for (size_t i = 0; i < n; i++)
    {
        cout<<'*';
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    pat(n);
    return 0;
}
