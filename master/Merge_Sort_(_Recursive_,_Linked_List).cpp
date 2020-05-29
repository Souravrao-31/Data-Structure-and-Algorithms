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

node *mergeSort(node *head)
{
    if (!head or !head->next)
        return head;
    node *fast = head->next, *slow = head;
    while (fast and fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    node *first = head;
    node *second = slow->next;
    slow->next = nullptr;
    first = mergeSort(first);
    second = mergeSort(second);
    head = merge(first, second);
    return head;
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
    head = mergeSort(head);
    print(head);
    return 0;
}
