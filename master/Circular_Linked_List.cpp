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

node *search(node *head, int n)
{
    if (head == nullptr)
        return nullptr;
    while (head != nullptr)
    {
        if (head->data == n)
            return head;
        head = head->next;
    }
    return nullptr;
}

void insertEnd(node *&head, node *&tail, int n)
{
    if (head == nullptr)
    {
        head = tail = new node(n);
        return;
    }
    node *t = search(head, n);
    if (t != nullptr)
    {
        tail->next = t;
        tail = t;
    }
    else
    {
        tail->next = new node(n);
        tail = tail->next;
    }
}

void breakLoop(node *head)
{
    if(head==nullptr or head->next==nullptr) return;
    node *fast = head, *slow = head;
    while (fast != nullptr and fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }
    if (fast == slow and fast!=head)
    {
        fast = head;
        while (fast->next != slow->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast->next == slow->next)
            slow->next = nullptr;
    }
    if (fast == slow and fast == head)
    {
        while (fast->next!=head)
        {
            fast=fast->next;
        }
        fast->next=nullptr;
    }
}

int main()
{
    int t;
    cin >> t;
    node *head = nullptr, *tail = nullptr;
    while (t != -1)
    {
        insertEnd(head, tail, t);
        cin >> t;
    }
    breakLoop(head);
    print(head);

    return 0;
}
