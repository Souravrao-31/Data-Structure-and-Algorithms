#include <iostream>
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

node *create()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    node *root = new node(data);
    root->left = create();
    root->right = create();
    return root;
}

class Solution
{
public:
    node *prev = NULL;
    node *head = NULL;
    void TreeToLinkedList(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        TreeToLinkedList(root->left);
        if (prev == NULL)
        {
            head = root;
        }
        else
        {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        TreeToLinkedList(root->right);
    }
};

void print(node *head)
{
    while (head)
    {
        cout << head->data << "<->";
        head = head->right;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *root = create();
    Solution s;
    s.TreeToLinkedList(root);
    node *head = s.head;
    print(head);
    return 0;
}

// This problem is not completely solved
