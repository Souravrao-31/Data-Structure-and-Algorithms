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
int Max_sum(node*root){
    //base case
   if(root==NULL){
       return 0;
   }
 
  int g_max = INT8_MIN;

   //Reccursive case
   int ls = Max_sum(root->left);
   int rs = Max_sum(root->right);

   //self case
   int case1 = root->data;
   int case2 = ls + root->data;
   int case3 = rs + root->data;
   int case4 = ls + rs + root->data;

   g_max = max(case1 , max(case2,max(case3,max(case4,g_max))));
   return max(ls,max(rs,0)) + root->data;
}
int main()
{
    //O(n)
    node *root = buildTree();
    cout<<Max_sum(root);

    return 0;
}