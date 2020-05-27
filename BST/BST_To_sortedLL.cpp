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

class LinkedList
{
public:
    node *head;
    node *tail;
};

LinkedList flatten(node *root)
{
    LinkedList l;

    if (root == NULL)
    {
        l.head = l.tail = NULL;
        return l;
    }
    // Leaf Node
    if (root->left == NULL && root->right == NULL)
    {
        l.head = l.tail = root;
        return l;
    }
    // Left is Not NULL
    if (root->left != NULL && root->right == NULL)
    {
        LinkedList leftLL = flatten(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    //Right is Not NULL
    if (root->left == NULL && root->right != NULL)
    {
        LinkedList rightLL = flatten(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }
    //Both Sides are not NULL
    LinkedList leftLL = flatten(root->left);
    LinkedList rightLL = flatten(root->right);

    leftLL.tail->right = root;
    root->right = rightLL.head;

    l.head = leftLL.head;
    l.tail = rightLL.tail;
    return l;
}

int main()
{
    //5 3 7 1 6 8 -1
    node *root = buildtree();
    Inorder(root);
    cout << endl;
    BFS_2(root);
    cout << endl;

    LinkedList l = flatten(root);
    node *temp = l.head;

    while (temp != NULL)
    {
        cout << temp->data << " --> ";
        temp = temp->right;
    }
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    return 0;
}