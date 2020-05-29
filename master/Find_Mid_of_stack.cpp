// @author: Abhimanyu Maurya

#include <iostream>
#include <stack>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

stack<int> stk;
int cnt = 0;
void count()
{
    if (stk.empty())
        return;
    int t = stk.top();
    stk.pop();
    cnt++;
    count();
    stk.push(t);
}

int main()
{
    int t, n;
    cin >> n;
    while (n--)
    {
        cin >> t;
        stk.push(t);
    }
    count();
    cnt /= 2;
    while (cnt--)
    {
        stk.pop();
    }
    cout << stk.top();
    return 0;
}
