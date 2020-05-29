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

node *merge(node *h1, node *h2)
{
    if (!h1)
        return h2;
    if (!h2)
        return h1;
    node *head;
    if (h1->data < h2->data)
    {
        h1->next = merge(h1->next, h2);
        head = h1;
    }
    else
    {
        h2->next = merge(h1, h2->next);
        head = h2;
    }
    return head;
}

int main()
{
    int a, n,t;
    cin>>t;
    while (t--)
    {
        cin >> a;
        node *head1 = nullptr, *tail1 = nullptr;
        for (int i = 0; i < a; i++)
        {
            cin >> n;
            insertEnd(head1, tail1, n);
        }
        cin>>a;
        node *head2 = nullptr, *tail2 = nullptr;
        for (int i = 0; i < a; i++)
        {
            cin >> n;
            insertEnd(head2, tail2, n);
        }
        print(merge(head1,head2));
    }
    

    return 0;
}
