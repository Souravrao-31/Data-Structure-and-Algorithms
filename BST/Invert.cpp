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
        left = NULL;
        right = NULL;
    }
};
node *insert(node *root, int data)
{
    //old root node and return new root node old = null
    //updating the node

    //base case
    if (root == NULL)
    {
        return new node(data);
    }
    //Rec case - Insert in the subtree and update Pointers
    if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}
node *buildtree()
{
    //Read a list of numbers till -1 and also this number will be inserted to BST
    int d;
    cin >> d;
    node *root = NULL;
    while (d != -1)
    {
        root = insert(root, d);
        cin >> d;
    }
    return root;
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

node *Invert(node *root){
   //Recursion 
   //O(n)
   if(root == NULL){
      return NULL;
   }
   node *right = Invert(root->right);
   node *left = Invert(root->left);

   root->left =right;
   root->right =left;
   return root;

}

int main()
{
    //5 3 7 1 6 8 -1
    node *root = buildtree();
    BFS_2(root);

    Invert(root);
    cout << endl;

    BFS_2(root);

    return 0;
}