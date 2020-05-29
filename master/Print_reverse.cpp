#include<iostream>
#include<string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string num;
    cin>>num;
    for (int i = num.length() -1; i >=0; i--)
    {
        cout<<num[i];
    }
    return 0;
}
