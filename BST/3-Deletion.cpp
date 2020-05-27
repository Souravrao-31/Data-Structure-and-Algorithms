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

void Inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    //Left root right
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

node* DELETE_BST(node*root,int data){
    if(root == NULL){
        return NULL; 
    }
    else if(data < root->data){
       root->left =DELETE_BST(root->left,data);
       return root;
    }
    else if (data == root->data)
    {
        // 1. Node with 0 children
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // 2. Node with 1 children
        if(root->left != NULL && root->right==NULL){
           node*temp=root->left;
           delete root;
           return temp;
        }
        if (root->right != NULL && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // 3. Node with 2 child
        node*replace =root->right;
        while(replace->left != NULL){
            replace = replace->left;
        }
        root->data  = replace->data;
        root->right = DELETE_BST(root->right,replace->data);
        return root; 

    }
    else{
        root->right = DELETE_BST(root->right,data);
        return root;
    }
    
}

int main()
{
    //5 3 7 1 6 8 -1
    node *root = buildtree();
    BFS_2(root);
    cout << endl;
    Inorder(root); //IMP- Inorder print in BSt is always sorted
    int d;
    cin>>d;

    DELETE_BST(root,d);
    
    //after delete
    BFS_2(root);
    cout << endl;
    Inorder(root);

    return 0;
}