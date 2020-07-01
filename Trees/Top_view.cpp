#include <bits/stdc++.h>
using namespace std;

// Structure of binary tree
struct Node
{
    Node *left;
    Node *right;
    int data;
};

// function to create a new node
Node *newNode(int key)
{
    Node *node = new Node();
    node->left = node->right = NULL;
    node->data = key;
    return node;
}

// function to fill the map
void fillMap(Node *root, int d, int l, map<int, pair<int, int>> &m)
{
    if (root == NULL)
        return;

    if (m.count(d) == 0)
    {
        m[d] = make_pair(root->data, l);
    }
    else if (m[d].second > l)
    {
        m[d] = make_pair(root->data, l);
    }

    fillMap(root->left, d - 1, l + 1, m);
    fillMap(root->right, d + 1, l + 1, m);
}

// function should print the topView of
// the binary tree
void topView(struct Node *root)
{

    //map to store the pair of node value and its level
    //with respect to the vertical distance from root.
    map<int, pair<int, int>> m;

    //fillmap(root,vectical_distance_from_root,level_of_node,map)
    fillMap(root, 0, 0, m);

    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->second.first << " ";
    }
}
// Driver Program to test above functions
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
    cout << "Following are nodes in top view of Binary Tree\n";
    topView(root);
    return 0;
}
/* This code is contributed by Akash Debnath */
