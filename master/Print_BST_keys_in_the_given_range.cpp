/*
* @Date    : 2020-04-12 15:43:12
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <iostream>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int n);
    ~Node();
};

Node::Node(int n)
{
    data = n;
    left = nullptr;
    right = nullptr;
}

Node::~Node()
{
}

void insertInBT(Node *r, int d)
{

    if (d < r->data)
    {
        if (!r->left)
            r->left = new Node(d);
        else
            insertInBT(r->left, d);
    }
    else
    {
        if (!r->right)
            r->right = new Node(d);
        else
            insertInBT(r->right, d);
    }
}

void printBT(const Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    printBT(root->left);
    printBT(root->right);
}

void printBTR(const Node *root, int l, int r)
{
    if (!root)
        return;
    printBTR(root->left, l, r);
    if (root->data <= r and root->data >= l)
        cout << root->data << " ";
    printBTR(root->right, l, r);
}

int main()
{
    int t, n, l, r, num;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if(n==0) continue;
        cin >> num;
        Node *root = new Node(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            insertInBT(root, num);
        }

        cin >> l >> r;
        cout << "# Preorder : ";
        printBT(root);
        cout << '\n';
        cout << "# Nodes within range are : ";
        printBTR(root, l, r);
        cout << '\n';
    }

    return 0;
}
