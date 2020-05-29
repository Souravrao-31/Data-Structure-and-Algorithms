/*
* @Date    : 2020-04-10 17:19:06
* @Author  : Abhimanyu Kumar Maurya (aerma7309@gmail.com)
* @Link    : fb.com/aerma7309
*/
#include <iostream>
#include<queue>
using namespace std;

bool ib = ios_base::sync_with_stdio(0);
bool it = cin.tie(0);

class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int n);
    ~Node();
};

Node::Node(int n)
{
    data = n;
    left = nullptr;
    right = nullptr;
}

Node::~Node()
{
}

Node *createBT()
{
    string response;
    cin >> response;
    if (response == "false")
        return nullptr;
    int n;
    cin >> n;
    Node *root = new Node(n);
    root->left = createBT();
    root->right = createBT();
    return root;
}

void printLevelOrder(Node *root)
{
    if (!root)
        return; 
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    Node* temp;
    while (!q.empty())
    {
        temp = q.front();
        if(!temp and q.size()>1) 
        {
            q.pop();
            cout<<"\n";
            q.push(nullptr);
        }
        else if (!temp)
        q.pop();
        else
        {
            cout<<temp->data<<" ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            q.pop();
        }   
    }  
}



int main()
{
    int n;
    cin >> n;
    Node *root = new Node(n);
    root->left = createBT();
    root->right = createBT();
    printLevelOrder(root);
    return 0;
}
