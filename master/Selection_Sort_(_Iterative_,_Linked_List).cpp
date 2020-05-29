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

int count(node *h)
{
    int cnt = 0;
    while (h)
    {
        cnt++;
        h = h->next;
    }
    return cnt;
}

void SelSort(node *h)
{
    int size = count(h);
    node *start = h;
    for (int i = 0; i < size - 1; i++)
    {
        node *min = start, *selpos = start;
        while (selpos->next)
        {
            selpos = selpos->next;
            if (selpos->data < min->data)
                min = selpos;
        }
        if (min != start)
            swap(min->data, start->data);
        start = start->next;
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
    SelSort(head);
    print(head);
    return 0;
}
