// @author: Abhimanyu Maurya

#include <iostream>
#include <queue>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

queue<int> Q;

void revQRec()
{
    if (Q.empty())
        return;
    int t = Q.front();
    Q.pop();
    revQRec();
    Q.push(t);
}

int main()
{
    int t, n;
    cin >> n;
    while (n--)
    {
        cin >> t;
        Q.push(t);
    }
    revQRec();
    while (!Q.empty())
    {
        cout << Q.front() << ' ';
        Q.pop();
    }
    cout << "END";
    return 0;
}
