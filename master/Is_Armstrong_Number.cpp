#include<iostream>
#include<cmath>
using namespace std;
int numLength(int n)
{
    int cnt=0;
    do
    {
        cnt++;
        n/=10;
    } while (n != 0);
    return cnt;
}

bool isArmstrong(int n)
{
    int p=numLength(n),temp=0,num=n;
    while (num != 0)
    {
        temp+=(int)pow(num%10,p);
        num/=10;
    }
    return temp==n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(isArmstrong(n))
        cout<<"true";
    else
        cout<<"false";
    return 0;
}
