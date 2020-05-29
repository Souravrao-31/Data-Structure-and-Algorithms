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
    if (tail->data == n)
        return;
    tail->next = new node(n);
    tail = tail->next;
}

int main()
{
    int a, n, t;
    cin >> t;
    while (t--)
    {
        cin >> a;
        node *head = nullptr, *tail = nullptr;
        for (int i = 0; i < a; i++)
        {
            cin >> n;
            insertEnd(head, tail, n);
        }
        print(head);
    }
    return 0;
}
