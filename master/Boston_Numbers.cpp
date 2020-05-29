/*
* @Date    : 2020-05-27 16:41:14
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

int sumOfDigits(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}

signed main()
{
    int n;
    cin >> n;
    int num = n, factor_sum = 0, digit_sum = 0;

    for (int i = 2; i <= sqrt(n); i++)
    {
        while (num % i == 0)
        {
            factor_sum += sumOfDigits(i);
            num /= i;
        }
    }
    digit_sum = sumOfDigits(n);
    if (num > 1)
        factor_sum += sumOfDigits(num);
    if (digit_sum == factor_sum)
        cout << 1;
    else
        cout << 0;
    return 0;
}
