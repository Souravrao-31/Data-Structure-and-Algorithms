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

void kappend(node *&head, int n, int k)
{
    if (k == 0 or n == 0)
        return;
    node *t = head, *newTail = nullptr, *newHead = head;
    while (k > 1)
    {
        t = t->next;
        k--;
    }
    while (t->next != nullptr)
    {
        newTail = newHead;
        newHead = newHead->next;

        t = t->next;
    }
    if (t->next == nullptr)
    {
        newTail->next = nullptr;
        t->next = head;
        head = newHead;
    }
}

int main()
{
    node *head = nullptr;
    int a, b, temp;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> temp;
        insertEnd(head, temp);
    }
    cin >> b;
    kappend(head, a, b % a);
    print(head);
    return 0;
}
