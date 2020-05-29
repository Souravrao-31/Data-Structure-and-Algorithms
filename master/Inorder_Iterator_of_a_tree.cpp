#include <bits/stdc++.h>
using namespace std;

/*
* Node class definition for your reference. 
* Do not modify this class or your code may not work.
*/
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

class TreeIterator
{
public:
    Node *iter = NULL;

    Node *flatten(Node *root)
    {
        if (!root)
            return root;
        if (!root->left and !root->right)
            return root;
        Node *ll = NULL;
        Node *l = flatten(root->left);
        Node *r = flatten(root->right);
        if (!l and r)
        {
            root->right = r;
            root->left = NULL;
            ll = root;
        }
        else if (l and !r)
        {
            ll = l;
            Node *t = ll;
            while (t->right != NULL)
                t = t->right;
            root->left = NULL;
            t->right = root;
        }
        else
        {
            ll = l;
            Node *t = ll;
            while (t->right != NULL)
                t = t->right;
            t->right = root;
            root->left = NULL;
            root->right = r;
        }
        return ll;
    }

    TreeIterator(Node *root)
    {
        iter = flatten(root);
    }

    /** @return the next smallest number */
    int next()
    {
        int t = iter->data;
        iter = iter->right;
        return t;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return iter;
    }
};

/*
*
*
*   You do not need to refer or modify any code below this. 
*   Only modify the TreeIterator class definition.
*
*
*/

Node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }
    Node *root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int main()
{
    Node *root = buildTree();

    TreeIterator t(root);
    int c = 0;

    while (t.hasNext())
    {
        if (c / 10 % 2 == 1)
        {
            cout << t.hasNext() << " ";
        }
        if (c % 7 == 0)
        {
            cout << "^ ";
        }
        cout << t.next() << " ";
        c++;
    }

    return 0;
}