// @author: Abhimanyu Maurya

#include <iostream>
#include <stack>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

stack<int> stk;

void insAtBotm(int t)
{
    if (stk.empty())
    {
        stk.push(t);
        return;
    }
    int k = stk.top();
    stk.pop();
    insAtBotm(t);
    stk.push(k);
}

void revStkRec()
{
    if (stk.empty())
        return;
    int t = stk.top();
    stk.pop();
    revStkRec();
    insAtBotm(t);
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
    revStkRec();
    while (!stk.empty())
    {
        cout << stk.top() << '\n';
        stk.pop();
    }
    return 0;
}
