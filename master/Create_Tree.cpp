/*
* @Date    : 2020-04-10 16:13:25
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

Node *createBT(int post[], int in[], int &k, int start, int end)
{
    if (start > end)
        return nullptr;
    int index = -1;
    for (int i = end; i >= start; i--)
    {
        if (in[i] == post[k])
        {
            index = i;
            break;
        }
    }

    Node *root = new Node(post[k--]);
    root->right = createBT(post, in, k, index + 1, end);
    root->left = createBT(post, in, k, start, index - 1);

    return root;
}

void printPreOrder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int len;
        cin >> len;
        int inorder[len], postorder[len], k = len - 1;
        for (int i = 0; i < len; i++)
            cin >> inorder[i];
        for (int i = 0; i < len; i++)
            cin >> postorder[i];
        Node *root = createBT(postorder, inorder, k, 0, len - 1);
        printPreOrder(root);
    }

    return 0;
}
