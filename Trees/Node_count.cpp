#include <iostream>
#include <queue>
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
        right = NULL;
        left = NULL;
    }
};

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

int Count(node *root)
{
    /*
    it will count the total node
    O(n)
    */
    if (root == NULL)
    {
        return 0;
    }

    return 1 + Count(root->left) + Count(root->right);
}

int main()
{

    node *root = buildTree();
    cout<<Count(root)<<endl;

    return 0;
}