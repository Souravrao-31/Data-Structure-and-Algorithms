#include <iostream>
#include <cmath>
using namespace std;
int numLength(int n)
{
    int cnt = 0;
    do
    {
        cnt++;
        n /= 10;
    } while (n != 0);
    return cnt;
}

bool isArmstrong(int n)
{
    int p = numLength(n), temp = 0, num = n;
    while (num != 0)
    {
        temp += (int)pow(num % 10, p);
        num /= 10;
    }
    return temp == n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n1,n2;
    cin >> n1>>n2;
    for (int i = n1; i <= n2; i++)
    {
        if(isArmstrong(i))
            cout<<i<<endl;
    }
    
    return 0;
}
