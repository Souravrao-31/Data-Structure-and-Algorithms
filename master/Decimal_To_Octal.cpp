#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int dec,oct = 0,p=1;
    cin >> dec;
    while (dec > 0)
    {
        oct=oct+(dec%8)*p;
        dec /= 8;
        p*=10;
    }
    cout << oct;
    return 0;
}