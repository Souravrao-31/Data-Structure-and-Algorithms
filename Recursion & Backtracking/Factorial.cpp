#include <iostream>
using namespace std;

int Facto(int n)
{
    int ans;
    if (n == 1)
    {
        return 1;
    }
    ans = n * Facto(n - 1);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << Facto(n);
    return 0;
}