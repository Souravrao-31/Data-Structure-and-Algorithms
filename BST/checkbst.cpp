#include <bits/stdc++.h>

using namespace std;

/* A binary tree node has data, 
pointer to left child and 
a pointer to right child */
class node
{
public:
    int data;
    node *left;
    node *right;

    /* Constructor that allocates 
	a new node with the given data 
	and NULL left and right pointers. */
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isBSTUtil(node *root, int min, int max);

/* Returns true if the given 
tree is a binary search tree 
(efficient version). */
bool isBST(node *root)
{
    return (isBSTUtil(root, INT_MIN, INT_MAX));
}

/* Returns true if the given 
tree is a BST and its values 
are >= min and <= max. */
bool isBSTUtil(node *root, int min, int max)
{
    /* an empty tree is BST */
    if (root == NULL)
        return true;

    /* false if this node violates 
	the min/max constraint */
    if (root->data < min || root->data > max)
        return false;

    /* otherwise check the subtrees recursively, 
	tightening the min or max constraint */
    return isBSTUtil(root->left, min, root->data - 1) && // Allow only distinct values
           isBSTUtil(root->right, root->data + 1, max);  // Allow only distinct values
}

/* Driver code*/
int main()
{
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);

    if (isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";

    return 0;
}

// This code is contributed by rathbhupendra
