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

/*
BFS(Breadth first search)
in O(n)

its also a level order print bt in efficient order.


in function levelorder complexity is more thats why we are using BFS.

using queue

*/
void BFS(node *root)
{

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {

        node *f = q.front();
        cout << f->data << ", ";
        q.pop();

        if (f->left)
        {
            q.push(f->left);
        }
        if (f->right)
        {
            q.push(f->right);
        }
    }
    return;
}
void BFS_2(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        node *f = q.front();

        if (f == NULL)
        {

            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << f->data << " ";
            q.pop();

            if (f->left)
            {
                q.push(f->left);
            }
            if (f->right)
            {
                q.push(f->right);
            }
        }
    }
    return;
}

int Replace_sum(node*root){
    if(root==NULL){
       return 0;
    }
    if(root->left == NULL && root->right==NULL){
        return root->data;
    }
    int leftsum = Replace_sum(root->left);
    int rightsum =Replace_sum(root->right);

    int temp =root->data;
    root->data = leftsum + rightsum;
    return temp + root->data;

}
int main()
{
    //8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    node *root = buildTree();
   // BFS(root);
    //cout << endl;
    Replace_sum(root);
    BFS_2(root);

    return 0;
}