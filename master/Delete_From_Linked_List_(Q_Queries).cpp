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

void delPos(node *&h, int pos)
{
    if (!h)
        return;
    node *t = h;
    if (pos == 0)
    {
        h = h->next;
        delete t;
        return;
    }
    for (int i = 1; i < pos; i++)
    {
        t = t->next;
    }
    node *temp = t->next;
    t->next = t->next->next;
    delete temp;
}

int main()
{
    int a, b, n;
    cin >> a >> b;
    node *head = nullptr, *tail = nullptr;
    for (int i = 0; i < a; i++)
    {
        cin >> n;
        insertEnd(head, tail, n);
    }

    for (int i = 0; i < b; i++)
    {
        cin >> n;
        delPos(head, n);
        print(head);
    }

    return 0;
}
