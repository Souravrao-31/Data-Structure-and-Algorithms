#include <iostream>
using namespace std;

//normal approach
// int max_num(long n)
// {
//     long d=1;
//     for (int i = 0;n>=d ; i++) d*=2;
//     return d/2;
// }

// int cal_step(long n)
// {
//     if(n==0) return 0;
//     int t = max_num(n);
//     if(n==1||n==2|| n==t) return 1;
//     return 1+cal_step(n-t);
// }

// using bitmasking
int cal_step(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (n & 1)
        {
            count++;
        }
        n = n >> 1;
    }
    return count;
}
int main()
{
    int t;
    long num;
    cin >> t;
    while (t--)
    {
        cin >> num;
        cout << cal_step(num) << "\n";
    }
    return 0;
}
