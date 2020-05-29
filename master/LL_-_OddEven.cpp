// @author: Abhimanyu Maurya

#include <iostream>
using namespace std;

//fast i/o
bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);
bool ot = cout.tie(0);

class node
{
public:
    int data;
    node *next;
    node(int n);
    ~node();
};

node::node(int n)
{
    data = n;
    next = nullptr;
}

node::~node()
{
}

void print(node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

void insertEnd(node *&head, node *&tail, int n)
{
    if (head == nullptr)
    {
        head = tail = new node(n);
        return;
    }
    tail->next = new node(n);
    tail = tail->next;
}

void evenOdd(node *&h)
{
    node *eh = nullptr, *et = nullptr, *oh = nullptr, *ot = nullptr, *temp = nullptr;
    while (h)
    {
        temp = h;
        h = h->next;
        temp->next = nullptr;

        if (temp->data & 1)
        {
            if (!oh)
                oh = ot = temp;
            else
            {
                ot->next = temp;
                ot = temp;
            }
        }
        else
        {
            if (!eh)
                eh = et = temp;
            else
            {
                et->next = temp;
                et = temp;
            }
        }
    }
    if (oh)
    {
        h = oh;
        ot->next = eh;
    }
    else h = eh;
}

int main()
{
    int a, n;
    cin >> a;
    node *head = nullptr, *tail = nullptr;
    for (int i = 0; i < a; i++)
    {
        cin >> n;
        insertEnd(head, tail, n);
    }
    evenOdd(head);
    print(head);
    return 0;
}
