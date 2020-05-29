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

void bubble_sort(node* &h)
{
    int n=0;
    node * t=h;
    while (t)
    {
        n++;
        t=t->next;
    }
    for (int i = 0; i < n-1; i++)
    {
        t=h;
        while (t->next)
        {
            if(t->data > t->next->data)
            {
                int temp =t->data;
                t->data = t->next->data;
                t->next->data = temp;
            }
            t = t->next;
        } 
    }
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
    bubble_sort(head);
    print(head);
    return 0;
}
