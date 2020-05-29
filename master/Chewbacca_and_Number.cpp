#include<iostream>
#include<string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string num;
    cin>>num;
    int temp,inv;
    bool flag=true;
    for (long long i = 0; i < num.length(); i++)
    {
        temp = num[i] -'0';
        inv = 9-temp;
        if(i==0 && inv==0)
        {
            inv = temp;
        }
        if (inv < temp)
        {
            num[i] = inv + '0';
        }
    }
    cout<<num;
    return 0;
}
