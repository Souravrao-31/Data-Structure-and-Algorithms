#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// root - Root of the Binary Tree
// This function should return the head of the resultant linked list
node *flatten(node *root)
{
    if (!root)
        return root;
    if (!root->left and !root->right)
        return root;
    node *ll = NULL;
    node *l = flatten(root->left);
    node *r = flatten(root->right);
    if (!l and r)
    {
        root->right = r;
        root->left = NULL;
        ll = root;
    }
    else if (l and !r)
    {
        ll = l;
        node *t = ll;
        while (t->right != NULL)
            t = t->right;
        root->left = NULL;
        t->right = root;
    }
    else
    {
        ll = l;
        node *t = ll;
        while (t->right != NULL)
            t = t->right;
        t->right = root;
        root->left = NULL;
        root->right = r;
    }
    return ll;
}

void printLinkedList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->left != NULL)
        {
            cout << "Left pointer for node with data=" << temp->data << " is changed to NULL" << endl;
        }
        cout << temp->data << " ";
        temp = temp->right;
    }
}

node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int main()
{
    node *root = buildTree();

    node *head = flatten(root);

    printLinkedList(head);

    return 0;
}
