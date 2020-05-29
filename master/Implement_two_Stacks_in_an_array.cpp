// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

int stack[1000000], top1, top2, N;

int stkTop(int stkID)
{
    if (stkID == 1)
        return stack[top1];
    else
        return stack[top2];
}

bool isEmpty(int stkID)
{
    if (stkID == 1 and top1 == -1)
        return true;
    if (stkID == 2 and top2 == N)
        return true;
    return false;
}

void stkPop(int stkID)
{
    int t;
    if (stkID == 1)
    {
        t = stack[top1];
        top1--;
    }
    if (stkID == 2)
    {
        t = stack[top2];
        top2++;
    }
}

void stkPush(int stkID, int data)
{
    if (stkID == 1)
    {
        top1++;
        stack[top1] = data;
    }
    if (stkID == 2)
    {
        top2--;
        stack[top2] = data;
    }
}

void stkPrint(int stkID)
{
    while (!isEmpty(stkID))
    {
        cout << stkTop(stkID) << ' ';
        stkPop(stkID);
    }
}

int main()
{
    int n, m, t;
    cin >> N >> n >> m;
    top1 = -1;
    top2 = N;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        stkPush(1, t);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        stkPush(2, t);
    }
    if (n == 0)
        cout << "None";
    else
    {
        cout << stkTop(1) << '\n';
        stkPop(1);
    }
    if (m == 0)
        cout << "None";
    else
    {
        cout << stkTop(2) << '\n';
        stkPop(2);
    }
    cout << "Elements in stack1 are\n";
    if (isEmpty(1))
        cout
            << "None";
    else
        stkPrint(1);
    cout << "\n";
    cout << "Elements in stack2 are\n";
    if (isEmpty(2))
        cout
            << "None";
    else
        stkPrint(2);
    return 0;
}
