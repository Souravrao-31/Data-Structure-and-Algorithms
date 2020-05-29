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

node *recRev(node *h)
{
    if (!h->next)
        return h;

    node *bakiKaReverse = recRev(h->next);
    node *t = bakiKaReverse;
    while (t->next)
    {
        t = t->next;
    }
    t->next = h;
    h->next = nullptr;
    return bakiKaReverse;
}

node *kRev(node *&h, int k)
{
    if (!h)
        return h;
    int c = 0;
    node *cur = h, *res = nullptr;
    while (cur and c < k - 1)
    {
        cur = cur->next;
        c++;
    }
    if (cur->next)
    {
        res = kRev(cur->next, k);
        cur->next = nullptr;
        h = recRev(h);
        cur = h;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = res;
    }
    else
        h = recRev(h);
    return h;
}

int main()
{
    int n, num, k;
    cin >> n >> k;
    node *head = nullptr, *tail = nullptr;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        insertEnd(head, tail, num);
    }
    kRev(head, k);
    print(head);
    return 0;
}
