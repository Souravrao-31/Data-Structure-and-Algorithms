// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

void prntPat(int n)
{
    if (n == 0)
        return;
    else
    {

        for (int i = 0; i < n; i++)
        {
            cout << "*    ";
        }
        cout << "\n";
        prntPat(n - 1);
    }
}

int main()
{
    int n;
    cin >> n;

    prntPat(n);
    return 0;
}
