/*
task is to print the right view of the tree
      1
   2     3
 10  5      4
    6
   
   ANS- 1, 3, 4 , 6

   for preorder,inorder,postorder we will use....Depth first search
   and for level order BFS.


*/
#include <iostream>
#include <queue>
#include<vector>
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
    int count=0;
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
class RightT {
  public:
    vector<int> v;
    int max_level =-1;
    void helper(node*root,int level){
        if(root == NULL){
           return;
        }
        if(level > max_level){
            max_level =level;
            v.push_back(root->data);
            cout<<root->data<<" ";
        }
        helper(root->right,level + 1);
        helper(root->left, level + 1);
    }
    vector<int> rightsideView(node*root){
        //logic
        helper(root,0);
        return v;    
    }
};

int main()
{

    node *root = buildTree();
   //1 2 3 4 5 6  -1 -1 -1 -1 -1 -1 -1
    RightT c;
    c.rightsideView(root);   //1 3 6


    return 0;
}