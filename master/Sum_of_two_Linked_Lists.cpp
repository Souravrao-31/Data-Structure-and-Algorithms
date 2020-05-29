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

void insertFront(node *&head, int n)
{
    if (head == nullptr)
    {
        head = new node(n);
    }
    else
    {
        node *t = new node(n);
        t->next = head;
        head = t;
    }
}

void insertEnd(node *&head, int n)
{
    if (head == nullptr)
    {
        head = new node(n);
        return;
    }
    node *curr = head, *nxt = head->next;
    while (nxt != nullptr)
    {
        curr = nxt;
        nxt = nxt->next;
    }
    curr->next = new node(n);
}

int sumlist(node *a, node *b, int m, int n)
{
    if (m == n and m == 1)
    {
        int carry = (a->data + b->data) / 10;
        a->data = (a->data + b->data) % 10;
        return carry;
    }
    if (m != n)
    {
        int t = sumlist(a->next, b, m - 1, n) + a->data;
        int carry = t / 10;
        a->data = t % 10;
        return carry;
    }
    int t = sumlist(a->next, b->next, m - 1, n - 1) + a->data + b->data;
    int carry = t / 10;
    a->data = t % 10;
    return carry;
}

int main()
{
    node *head1 = nullptr;
    node *head2 = nullptr;

    int a, b, temp;
    cin >> a >> b;
    for (int i = 0; i < a; i++)
    {
        cin >> temp;
        insertEnd(head1, temp);
    }
    for (int i = 0; i < b; i++)
    {
        cin >> temp;
        insertEnd(head2, temp);
    }
    if (a >= b)
    {
        int carry = sumlist(head1, head2, a, b);
        if (carry > 0)
            cout << carry << " ";
        print(head1);
    }
    else
    {
        int carry = sumlist(head2, head1, b, a);
        if (carry > 0)
            cout << carry << " ";
        print(head2);
    }
    return 0;
}
