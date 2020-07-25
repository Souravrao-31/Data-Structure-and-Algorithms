
#include <iostream>
#include <queue>
#include <vector>
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
     int count =0;
     int d;
    queue<node*> q;

    cin>>d;
    node *root=new node(d);
    node *cur=root;
    root=cur;

    while(1)
    {
        cin>>d;
        if(d!=-1)
        {
            if(count==0)
            {
                cur->left=new node(d);
                count++;
                q.push(cur->left);
        
            }

            else if(count==1)
            {
                cur->right=new node(d);
                q.push(cur->right);
                
                count=0;
                
                if(q.front())
                cur=q.front();
                
                q.pop();
            }
        } 

        else if(d==-1)
        {
            if(count==0)
            count++;

            else
            {
                count=0;
                if(q.front())
                cur=q.front();

                q.pop();
            }
        }       

        if(q.empty())
        return root;

        
    }

}


//O(n),O(n).
class LeftT
{
public:
    vector<int> v;
    int max_level = -1;
    void helper(node *root, int level)
    {
        if (root == NULL)
        {
            return;
        }
        if (level > max_level)
        {
            max_level = level;
            v.push_back(root->data);
            cout << root->data << " ";
        }
        helper(root->left, level + 1);
        helper(root->right, level + 1);
    }
    vector<int> leftsideView(node *root)
    {
        //logic
        helper(root, 0);
        return v;
    }
};

int main()
{

    node *root = buildTree();
    //1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
    LeftT c;
    c.leftsideView(root);
   

        return 0;
}