// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

int cal(int n)
{
    if (n == 0)
        return n;
    return n + cal(n - 1);
}

int main()
{
    int n;
    cin>>n;
    cout << cal(n);

    return 0;
}
