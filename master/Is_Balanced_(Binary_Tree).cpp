/*
* @Date    : 2020-04-06 20:46:23
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
* @Link    : fb.com/aerma7309
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

Node *createBT()
{
    string response;
    cin >> response;
    if (response == "false")
        return nullptr;
    int n;
    cin >> n;
    Node *root = new Node(n);
    root->left = createBT();
    root->right = createBT();
    return root;
}

void printBT(const Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    printBT(root->left);
    printBT(root->right);
}

pair<int, bool> isBalanced(Node *root)
{
    if (!root)
        return make_pair(0, true);
    pair<int, bool> l = isBalanced(root->left);
    pair<int, bool> r = isBalanced(root->right);
    if (abs(l.first - r.first) <= 1 and l.second and r.second)
        return make_pair(max(l.first, r.first) + 1, true);
    return make_pair(max(l.first, r.first) + 1, false);
}

int main()
{
    int n;
    cin >> n;
    Node *root = new Node(n);
    root->left = createBT();
    root->right = createBT();
    if (isBalanced(root).second)
        cout << "true";
    else
        cout << "false";
    return 0;
}
