
#include <bits/stdc++.h>
using namespace std;
#define sync                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
    
void nextPalindrome(string &num)
{
    int n = num.size();
    int mid = n / 2;
    bool leftsmaller = false;

    int i = mid - 1;
    int j = (n % 2) ? mid + 1 : mid;

    while (i >= 0 && num[i] == num[j])
        i--, j++;

    if (i < 0 || num[i] < num[j])
        leftsmaller = true;

    while (i >= 0)
    {
        num[j] = num[i];
        j++;
        i--;
    }

    if (leftsmaller)
    {
        int carry = 1;
        i = mid - 1;

        if (n % 2 == 1)
        {
            int x = num[mid] - '0';
            x += carry;
            carry = x / 10;
            x %= 10;
            num[mid] = x + '0';
            j = mid + 1;
        }
        else
            j = mid;

        while (i >= 0)
        {
            int x = num[i] - '0';
            x += carry;
            carry = x / 10;
            x %= 10;
            num[i] = x + '0';
            num[j++] = num[i--];
        }
    }
}

void generateNextPalindrome(string &num)
{
    if (num == string(num.size(), '9'))
    {
        cout << 1;
        for (int i = 1; i < num.size(); i++)
            cout << 0;
        cout << 1;
    }
    else
    {
        nextPalindrome(num);
        cout << num;
    }
}

int main()
{
    sync;
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        string s ;
        cin >> s;
        generateNextPalindrome(s);
        cout<<'\n';
    }

    return 0;
}