/*
* @Date    : 2020-05-06 22:30:46
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
*/
#include <bits/stdc++.h>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

Node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
        return nullptr;
    Node *root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int sum = 0;

void change(Node *root)
{
    if (!root)
        return;
    change(root->right);
    sum += root->data;
    root->data = sum;
    change(root->left);
}

void printPreOrder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

signed main()
{
    Node *root = buildTree();
    change(root);
    printPreOrder(root);
    return 0;
}
