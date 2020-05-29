/*
* @Date    : 2020-04-10 16:08:17
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

Node *createBT(int pre[], int in[], int &k, int start, int end)
{
    if (start > end)
        return nullptr;
    int index = -1;
    for (int i = start; i <= end; i++)
    {
        if (in[i] == pre[k])
        {
            index = i;
            break;
        }
    }

    Node *root = new Node(pre[k++]);
    root->left = createBT(pre, in, k, start, index - 1);
    root->right = createBT(pre, in, k, index + 1, end);
    return root;
}

void printBT(const Node *root)
{
    if (!root)
        return;
    if (!root->left)
        cout << "END ";
    else
        cout << root->left->data << " ";
    cout << "=> " << root->data << " <= ";
    if (!root->right)
        cout << "END\n";
    else
        cout << root->right->data << "\n";

    printBT(root->left);
    printBT(root->right);
}

int main()
{
    int inorder[100] = {0}, preorder[100] = {0}, k = 0;
    int len;
    cin >> len;
    for (int i = 0; i < len; i++)
        cin >> preorder[i];
    cin >> len;
    for (int i = 0; i < len; i++)
        cin >> inorder[i];
    Node *root = createBT(preorder, inorder, k, 0, len - 1);
    printBT(root);
    return 0;
}
