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

// void reverse(node *&c)
// {
//     node *p = nullptr, *n = nullptr;
//     while (c)
//     {
//         n = c->next;
//         c->next = p;
//         p = c;
//         c = n;
//     }
//     c = p;
// }

node * recRev(node* h)
{
    if(!h->next) return h;
    
    node* bakiKaReverse = recRev(h->next);
    node *t = bakiKaReverse;
    while (t->next)
    {
        t=t->next;
    }
    t->next=h;
    h->next=nullptr;
    return bakiKaReverse;
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
    // reverse(head);
    print(recRev(head));

    return 0;
}
